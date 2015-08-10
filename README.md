# xmc4500
Bare metal programming of Infeneon XMC4500

This project is for programming an XMC4500 RelaxKit Lite board
using only gcc and some Jlink tools. The XMC4500 RelaxKit Lite
is a nice board which at €10 is great value, 120KB RAM, 1MB flash 
and 120MHz Cortex-M4F core.

Necessary tools are:
 
JLink tools from Segger for talking to the debug chip and flash the code
https://www.segger.com/jlink-software-beta-version.html

GCC crosscompilation toolchain
https://launchpad.net/gcc-arm-embedded


basicblink_xmc4500
==================
This is the bare blink and read a button example. The files used are

Makefile					Path to arm-none-eabi toolchain must be set
flash_XMC4500-1024.ld		linkerfile
flash.jlink					Command script for JLinkExe to write program to flash

core_cm4.h					CMSIS definitions for the Cortex-M4F core
core_cm4_simd.h
core_cmFunc.h
core_cmInstr.h

vectorsxmc4500.c			Interrupt vectors
startup.c					Reset handler
/* Note revision AA and AB of the processor has a bug and the Infeneon startup_XMC4500.S must be used */
/* The latest boards I bought has revision AC of the processor */
/* Update this is not an issue if both normal code and interrupts use main stack pointer MSP */

System_XMC4500.c/h			Clock and lowlevel initialisation (Infenieon code from DAVE, I plan to rewrite them)
syscalls.c					some function stubs to make the C library happy
uc_id.h						Processor ID stuff from Infeneon
uc_id.inc

xmc4500.h					Register definitions
xmc4500_gpio.h				Some extra defins for GPIO

main.cpp					The main program

For me it works to do make clean, make, make flash. But this might depe
