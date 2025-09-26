# TejasOS 🚀

**TejasOS** is a simple educational operating system created by **Tejas Mahajan** for learning low-level system programming and OS development. It is written in **C** and uses **GRUB** as the bootloader — no assembly (NASM) is used at this stage.

## 🛠️ Project Structure
```   
myos/
├── boot/               # Bootloader (GRUB) related files
├── build/              # Compiled binaries (.o, .bin)
├── grub/               # GRUB configuration (grub.cfg)
├── include/            # Header files (.h) for drivers and kernel
│   ├── vga.h
│   └── keyboard.h
├── src/                # Source code (.c)
│   ├── kernel.c
│   ├── vga.c
│   └── keyboard.c
├── Makefile            # Build instructions
├── linker.ld           # Linker script
└── TejasOS.iso         # Bootable ISO (generated after build)
```

##⚙️Features (Implemented)

- Bootable kernel using GRUB (Multiboot compliant)
- Written entirely in C (no assembly needed)
- Displays “Hello from TejasOS!” on boot
- Keyboard input support (captures typed characters)
- Backspace handling for text input
- VGA driver for modular screen output (text printing + cursor control)
- Keyboard driver for modular input handling
- Modular code structure for easier debugging and future driver integration
- Easy to build and test on QEMU or VMware

## 📦 Build Instructions

1. Clone the repository :-
   ```
   git clone https://github.com/Tejasmahajan11/TEJASOS.git
   cd TEJASOS
   ```
3. Run `make` to build the project , If problem in rebuild and iso file  Run `make clean` then run `make`
4. Use ```qemu-system-x86_64 -cdrom TejasOS.iso``` to test the OS

## 🔭 Future Goals

- Add colorful text and improved cursor control
- Explore memory management and interrupt handling
- Further modularization of drivers for easier debugging
- Experiment with multi-boot features and extended kernel functionality

---

This project is a personal learning journey into OS internals and x86 architecture, built completely from scratch and open to improvements.

