CC=i686-elf-gcc
LD=i686-elf-ld

all: iso

kernel.o: src/kernel.c
	$(CC) -m32 -ffreestanding -c src/kernel.c -o kernel.o

kernel.bin: kernel.o
	$(LD) -m elf_i386 -T src/linker.ld -o kernel.bin kernel.o

iso: kernel.bin
	mkdir -p iso/boot/grub
	cp kernel.bin iso/boot/kernel.bin
	cp grub/grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o TejasOS.iso iso

run: iso
	qemu-system-x86_64 -cdrom TejasOS.iso

clean:
	rm -rf *.o *.bin iso TejasOS.iso

