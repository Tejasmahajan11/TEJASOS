#include "vga.h"

uint16_t* VIDEO_MEMORY = (uint16_t*)0xB8000;
int cursor = 0;

void clear_screen() {
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        VIDEO_MEMORY[i] = (uint16_t)' ' | (0x07 << 8); // white on black
    }
    cursor = 0;
}

void scroll_screen() {
    for (int i = 0; i < (VGA_HEIGHT - 1) * VGA_WIDTH; i++) {
        VIDEO_MEMORY[i] = VIDEO_MEMORY[i + VGA_WIDTH];
    }
    for (int i = (VGA_HEIGHT - 1) * VGA_WIDTH; i < VGA_HEIGHT * VGA_WIDTH; i++) {
        VIDEO_MEMORY[i] = (uint16_t)' ' | (0x07 << 8);
    }
    if(cursor >= VGA_WIDTH * VGA_HEIGHT) cursor = (VGA_HEIGHT - 1) * VGA_WIDTH;
}

void print_char(char c, int color) {
    if(c == '\n') {
        cursor += VGA_WIDTH - (cursor % VGA_WIDTH);
    } else {
        VIDEO_MEMORY[cursor++] = (uint16_t)c | (color << 8);
    }
    if(cursor >= VGA_WIDTH * VGA_HEIGHT) scroll_screen();
}

void print_string(const char* str, int color) {
    for(int i = 0; str[i] != '\0'; i++) {
        print_char(str[i], color);
    }
}
