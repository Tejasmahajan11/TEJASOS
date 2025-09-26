#include "keyboard.h"
#include "vga.h"
#include <stdbool.h>

#define KBD_DATA_PORT 0x60
#define KBD_STATUS_PORT 0x64

// Simple US keyboard scan code map for normal keys
char scancode_map[128] = {
    0,  27,'1','2','3','4','5','6','7','8','9','0','-','=','\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',
    0,'a','s','d','f','g','h','j','k','l',';','\'','`',0,
    '\\','z','x','c','v','b','n','m',',','.','/',0,'*',0,' ',
};

// ----------------------------
// Wait until keyboard input is ready
// ----------------------------
static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

// ----------------------------
// Read a key from keyboard
// ----------------------------
char keyboard_get_char() {
    uint8_t status = inb(KBD_STATUS_PORT);
    if(status & 0x01) {  // output buffer full
        uint8_t scancode = inb(KBD_DATA_PORT);
        if(scancode < 128) {
            return scancode_map[scancode];
        }
    }
    return 0;
}

// ----------------------------
// Backspace
// ----------------------------
void handle_backspace() {
    if(cursor > 0) {
        cursor--;
        VIDEO_MEMORY[cursor] = (uint16_t)' ' | (0x07 << 8);
    }
}

// ----------------------------
// Placeholder for init (optional for PS/2)
// ----------------------------
void keyboard_install() {
    // For now nothing needed, future IRQ installation
}
