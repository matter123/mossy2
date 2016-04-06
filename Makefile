all: run
.PHONY: all headers libs kernel iso clean build_info run

build_info:
	python3 gen_buildinfo.py

-include build_info
-include env_info

clean:
	$(MAKE) -C src/kernel clean
	$(MAKE) -C src/libc clean
	$(MAKE) -C src/libm clean
	$(MAKE) -C src/libacpica clean
	@-rm mossy.iso 2> /dev/null
	@-rm .build_number

headers:
	$(MAKE) -C src/kernel headers
	$(MAKE) -C src/libc headers
	$(MAKE) -C src/libm headers
	$(MAKE) -C src/libacpica headers

sysroot/usr/lib/libk: libs
sysroot/usr/lib/libm: libs
sysroot/usr/lib/libacpica: libs
libs: headers
	$(MAKE) -C src/libc
	$(MAKE) -C src/libm
	$(MAKE) -C src/libacpica

kernel: sysroot/boot/kernel
sysroot/boot/kernel: sysroot/usr/lib/libk sysroot/usr/lib/libm sysroot/usr/lib/libacpica
	$(MAKE) -C src/kernel

iso: mossy.iso
mossy.iso: sysroot/boot/kernel sysroot/boot/grub/grub.cfg
	grub2-mkrescue --compress=gz -o mossy.iso sysroot || grub-mkrescue --compress=gz -o mossy.iso sysroot

run: iso
	~/src/bochs/bochs -f bochs.rc -q
