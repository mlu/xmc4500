#
DEVICE = XMC4500-1024
# Cortex-M4
CPU = cortex-m4
#
#FPU = -mfloat-abi=soft
FPU = -D__FPU_PRESENT -mfloat-abi=hard -mfpu=fpv4-sp-d16
# List the object files involved in this project
OBJS = startup.o vectorsxmc4500.o System_XMC4500.o syscalls.o main.o 

# Location of toolchain
TOOLS = /Users/lundin/Toolchains/arm/bin/

# Specify the compiler to use
CC=$(TOOLS)arm-none-eabi-gcc
# Specify the assembler to use
AS=$(TOOLS)arm-none-eabi-as
# Specity the linker to use
LD=$(TOOLS)arm-none-eabi-ld
# Specity the object copy to use
OC=$(TOOLS)arm-none-eabi-objcopy
# Specity the size to use
SZ=$(TOOLS)arm-none-eabi-size

#CCFLAGS = -fno-common -nostdlib -nostartfiles -g -mcpu=cortex-m0  -Os -mthumb -Wa,-ahls,-mapcs-32  -I./
CCFLAGS = -g -fno-exceptions -mcpu=$(CPU) $(FPU) -DUC_ID=4501 -Os -mthumb -Wa,-ahls,-mapcs-32  -I./

AFLAGS = -g -mcpu=$(CPU) $(FPU) -DUC_ID=4501 -Os -mthumb -Wa,-ahls,-mapcs-32  -I./

# Linker commands
CLDFLAGS =  -fno-exceptions  -nostartfiles -mcpu=$(CPU) -mthumb $(FPU) $(LDPATHS) -Wl,--cref,-gc-sections,--script=flash_$(DEVICE).ld,-Map $@.map

# The default 'target' (output) is main.elf and it depends on the object files being there.
# These object files are linked together to create main.elf
main.bin : $(OBJS)
	touch $@.map
	$(CC) $(CLDFLAGS) -o main.elf $(OBJS) -lm
	$(OC) -O binary main.elf main.bin
	$(OC) -O ihex main.elf main.hex
	$(SZ) -A main.elf
	@echo "done"
	
flash: main.bin
	JLinkExe -device $(DEVICE) -CommanderScript flash.jlink

debug: main.bin
	JLinkGDBServer -silent -device $(DEVICE) -if SWD -speed 4000 &
	$(TOOLS)arm-none-eabi-gdb --tui -ex "target remote :2331" main.elf

clean: 
	rm $(OBJS) 
	rm *.lst
	rm *.map
	rm main.elf
	rm main.bin
	rm main.hex

%.o : %.c
	@ echo ".compiling C code std"
	$(CC) $(CCFLAGS)  -c $< -o $@ > $@.lst

%.o : %.cpp
	@ echo ".compiling C++ code std"
	$(CC) $(CCFLAGS)  -fno-rtti -c $< -o $@ > $@.lst

%.o : %.S
	@ echo ".compiling Assembler code std"
	$(CC) $(AFLAGS)  -c $< -o $@ > $@.lst

