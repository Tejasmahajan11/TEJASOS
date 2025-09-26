#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

extern uint16_t* VIDEO_MEMORY;
extern int cursor;

void clear_screen();
void scroll_screen();
void print_char(char c, int color);
void print_string(const char* str, int color);

#endif
