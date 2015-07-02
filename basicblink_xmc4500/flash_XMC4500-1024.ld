
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
SEARCH_DIR(.)

/* Memory Spaces Definitions */
MEMORY
{
	rom (rx)  : ORIGIN = 0x08000000, LENGTH = 0x00100000 /* cachedflash, 1024K */
	ram (rwx) : ORIGIN = 0x10000000, LENGTH = 0x00010000 /* sram, 64K */
	dsram1 (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00010000 /* sram, 64K */
	dsram2 (rwx) : ORIGIN = 0x30000000, LENGTH = 0x00008000 /* sram, 32K */
}

/* The stack size used by the application. NOTE: you need to adjust according to your application. */

__stack_size__ = DEFINED(__stack_size__) ? __stack_size__ : 0x3000;

/* Set stack top to end of RAM, and stack limit move down by
 * size of stack_dummy section */
 __StackTop = ORIGIN(ram) + LENGTH(ram);
 __StackLimit = __StackTop -  __stack_size__ ;
 PROVIDE(_estack = __StackTop);


/* Section Definitions */
SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        _sfixed = .;
        KEEP(*(.vectors .vectors.*))
        *(.text .text.* .gnu.linkonce.t.*)
        *(.glue_7t) *(.glue_7)
        *(.rodata .rodata* .gnu.linkonce.r.*)
        *(.ARM.extab* .gnu.linkonce.armextab.*)

        /* Support C constructors, and C destructors in both user code
           and the C library. This also provides support for C++ code. */
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        __preinit_array_start = .;
        KEEP (*(.preinit_array))
        __preinit_array_end = .;

        . = ALIGN(4);
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        __init_array_end = .;

        . = ALIGN(0x4);
        KEEP (*crtbegin.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*crtend.o(.ctors))

        . = ALIGN(4);
        KEEP(*(.fini))

        . = ALIGN(4);
        __fini_array_start = .;
        KEEP (*(.fini_array))
        KEEP (*(SORT(.fini_array.*)))
        __fini_array_end = .;

        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*crtend.o(.dtors))

        . = ALIGN(4);
        _efixed = .;            /* End of text section */
    } > rom

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    PROVIDE_HIDDEN (__exidx_start = .);
    .ARM.exidx :
    {
      *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > rom
    PROVIDE_HIDDEN (__exidx_end = .);

    . = ALIGN(4);
    _etext = .;

    .relocate : AT (_etext)
    {
        . = ALIGN(4);
        _srelocate = .;
        *(.ramfunc .ramfunc.*);
        *(.data .data.*);
        . = ALIGN(4);
        _erelocate = .;
    } > ram

    /* .bss section which is used for uninitialized data */
    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = . ;
        _szero = .;
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = . ;
        _ezero = .;
    } > ram

    . = ALIGN(4);
    _end = . ;

    /* stack section */
    /*
    .stack (NOLOAD):
    {
		. = __StackLimit;
        . = ALIGN(4);
         _sstack = .;
        . = . + __stack_size__;
        . = ALIGN(4);
        _estack = .;
    } > ram
*/

	.sdram1 (NOLOAD) :
    {
        . = ALIGN(4);
        _sdsram1 = .;
        *(.systemram .systemram.*);
        *(.data .data.*);
        . = ALIGN(4);
        _edsram1 = .;
    } > dsram1

}
