# Compiler and Linker
CC=i686-elf-gcc
LD=i686-elf-ld

# List of all object files (kernel + drivers)
OBJS=src/kernel.o src/vga.o src/keyboard.o

# Default target
all: iso

# -----------------------------
# Compile source files
# -----------------------------
src/kernel.o: src/kernel.c
	$(CC) -m32 -ffreestanding -Iinclude -c src/kernel.c -o src/kernel.o

src/vga.o: src/vga.c
	$(CC) -m32 -ffreestanding -Iinclude -c src/vga.c -o src/vga.o

src/keyboard.o: src/keyboard.c
	$(CC) -m32 -ffreestanding -Iinclude -c src/keyboard.c -o src/keyboard.o

# -----------------------------
# Link all objects into kernel
# -----------------------------
build/kernel.bin: $(OBJS)
	mkdir -p build
	$(LD) -m elf_i386 -T src/linker.ld -o build/kernel.bin $(OBJS)

# -----------------------------
# Create ISO
# -----------------------------
TejasOS.iso: build/kernel.bin
	mkdir -p iso/boot/grub
	cp build/kernel.bin iso/boot/kernel.bin
	cp grub/grub.cfg iso/boot/grub/grub.cfg
	grub-mkrescue -o TejasOS.iso iso

iso: TejasOS.iso

# -----------------------------
# Run QEMU (auto-build if missing)
# -----------------------------
run: TejasOS.iso
	qemu-system-x86_64 -cdrom TejasOS.iso

# -----------------------------
# Clean build files
# -----------------------------
clean:
	rm -rf src/*.o build/*.bin iso TejasOS.iso
