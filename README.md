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
- Displays “TejasOS Terminal:” on boot
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
3. Run `make` to build the project , If problem in rebuild an iso file then Run `make clean` and then run `make`
4. Use this to test the OS
   ```
   qemu-system-x86_64 -cdrom TejasOS.iso
   ```
### Software & Tools
- [VMware/VirtualBox](https://www.virtualbox.org/)  
- [GCC / G++ Compiler](https://gcc.gnu.org/) (for compiling C/C++)  
- [GNU Make](https://www.gnu.org/software/make/) (for build automation)  
- [NASM Assembler](https://www.nasm.us/) (if using Assembly code) `We haven't used this in the project yet`
- [GRUB Bootloader](https://www.gnu.org/software/grub/) (for OS development)  
- [QEMU](https://www.qemu.org/) (for virtualization & testing)   
- [Git](https://git-scm.com/) (for version control)
      
### Operating System
- Linux (Ubuntu 20.04 / 22.04 recommended)  
- Windows 10/11 (optional, but Linux preferred for development)  
- macOS (latest stable release)
  
## Installation & Setup

### 1. Install Dependencies (Linux - Ubuntu/Debian)
```bash
sudo apt update
sudo apt install build-essential nasm qemu-system-x86 grub-common git -y
```
## 🔭 Future Goals

- Add colorful text and improved cursor control
- Explore memory management and interrupt handling
- Further modularization of drivers for easier debugging
- Experiment with multi-boot features and extended kernel functionality

---

This project is a personal learning journey into OS internals and x86 architecture, built completely from scratch and open to improvements.

