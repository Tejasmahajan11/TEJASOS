// kernel.c

__attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
    0x1BADB002,      // Magic number
    0x0,             // Flags
    -(0x1BADB002)    // Checksum = -(magic + flags)
};

void kernel_main() {
    const char* msg = "Hello from TejasOS!";
    char* vga = (char*)0xB8000;
    for (int i = 0; msg[i] != '\0'; i++) {
        vga[i * 2] = msg[i];
        vga[i * 2 + 1] = 0x07; // White on black
    }
    while (1);
}
