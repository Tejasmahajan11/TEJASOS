#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

void keyboard_install();        // Initialize PS/2 keyboard
char keyboard_get_char();       // Get typed character
void handle_backspace();        // Handle backspace

#endif
