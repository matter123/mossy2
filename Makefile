CSOURCES=$(shell find -name *.c -not -path "./crt")
COBJECTS=$(patsubst %.c, %.o, $(CSOURCES))
CPPSOURCES=$(shell find -name *.cpp -not -path "./crt")
CPPOBJECTS=$(patsubst %.cpp, %.o, $(CPPSOURCES))
SSOURCES=$(shell find -name *.s)
SOBJECTS=$(patsubst %.s, %.o, $(SSOURCES))

64CC=$$HOME/opt/cross/bin/x86_64-elf-gcc
64CPP=$$HOME/opt/cross/bin/x86_64-elf-gcc
64LD=$$HOME/opt/cross/bin/x86_64-elf-gcc
64AS=$$HOME/opt/cross/bin/x86_64-elf-as

CRTBEGIN_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtbegin.o)
CRTEND_OBJ:=$(shell $(CC) $(CFLAGS) -print-file-name=crtend.o)

all: build test

build: clean check globalc $(COBJECTS) $(CPPOBJECTS) $(SOBJECTS) link

test: mkiso runem


WFLAGSON=-Wall -Wextra -Werror=return-type -Wshadow -Wframe-larger-than=16384 -Wdeprecated -Wredundant-decls -pedantic
WFLAGSOFF=-Wno-sequence-point -Wno-unused-parameter -Wno-sign-compare
FFLAGS=-fno-omit-frame-pointer -ffreestanding -fno-rtti -fno-exceptions -fno-stack-protector
DFLAGS=-DARCH=x64
MFLAGS=-mcmodel=large -mno-red-zone -mno-mxx -mno-sse -mno-sse2 -mno-sse3 -mno-3dnow
CFLAGS=-Isrc/stdlib/include -O2 -std=c99 $(DFLAGS) $(WFLAGSON) $(WFLAGSOFF) $(FFLAGS) $(MFLAGS)
CPPFLAGS=-Isrc/stdlib/include -O2 -std=c++11 $(DFLAGS) $(WFLAGSON) $(WFLAGSOFF) $(FFLAGS) $(MFLAGS)
LDFLAGS=-Tlink64.ld -ffreestanding -O2 -nostdlib
ASFLAGS=-felf

clean:
	@echo Cleaning workspace
	@find . -name '*.o' -delete
	@rm -f kernel

check:
	@tools/doccheck.py kernel src
link:
	@echo Linking
	$(LD) $(LDFLAGS) -o kernel ./gc/crti.o $(CRTBEGIN_OBJ) $(SOBJECTS) $(COBJECTS) $(CPPOBJECTS) $(CRTEND_OBJ) ./gc/crtn.o

.s.o:
	@echo Assembling $<
	@nasm $(ASFLAGS) $< -o $@

.c.o:
	@echo Compiling $<
	@$(CC) $(CFLAGS) -o $@ -c $<

.cpp.o:
	@echo Compiling $<
	@$(CPP) $(CPPFLAGS) -o $@ -c $<

mkiso:
	#@tools/packrd.py
	#@tools/symexport.py kernel
	@cp -f kernel iso/kernel
	@cp -f kernel.sym iso/kernel.sym
	#@cp -f initrd.rd iso/initrd.rd
	@grub2-mkrescue -o bootable.iso iso -- -zisofs level=6

runem:
	@cd .&& bash scripts/run_emulator `pwd` &

globalc:
	@echo assembling help files
	$(AS) ./gc/crti.asm -o ./gc/crti.o
	$(AS) ./gc/crtn.asm -o ./gc/crtn.o
