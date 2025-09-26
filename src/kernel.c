
 __attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
    0x1BADB002,      // Magic
    0x0,             // Flags
    -(0x1BADB002)    // Checksum
};



#include "vga.h"
#include "keyboard.h"

void kernel_main() {
    clear_screen();
    keyboard_install();
    print_string("TejasOS Terminal: ", 0x0A);

    char input_buffer[256];
    int input_index = 0;

    while(1) {
        char key = keyboard_get_char();
        if(key) {
            if(key == '\b') {          // backspace
                handle_backspace();
                if(input_index > 0) input_index--;
            } else if(key == '\n') {   // enter
                print_char('\n', 0x0A);
                input_index = 0;
            } else {                   // normal char
                print_char(key, 0x0A);
                input_buffer[input_index++] = key;
            }
        }
    }
}
