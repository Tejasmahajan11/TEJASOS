# TejasOS 🚀

**TejasOS** is a simple educational operating system created by **Tejas Mahajan** for learning low-level system programming and OS development. It is written in **C** and uses **GRUB** as the bootloader — no assembly (NASM) is used at this stage.

## 🛠️ Project Structure
   
****.       

## ⚙️ Features

- Bootable kernel using GRUB (Multiboot)
- Written entirely in C
- Displays “Hello from TejasOS!”
- Easy to build and test on QEMU/VMware

## 📦 Build Instructions

1. Clone the repository  
2. Run `make` to build the project  
3. Use `qemu-system-x86_64 -cdrom myos.iso` to test the OS

## 🔭 Future Goals

- Add keyboard input support  
- Implement colorful text and cursor control  
- Explore memory management and interrupts

---

This project is a personal learning journey into OS internals and x86 architecture, built completely from scratch and open to improvements.

