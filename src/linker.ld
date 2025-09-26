ENTRY(kernel_main)

SECTIONS
{
    . = 0x100000; /* Load kernel at 1 MB */

    /* Multiboot header must be first */
    .text : { *(.multiboot) *(.text*) }

    .rodata : { *(.rodata*) }

    .data : { *(.data*) }

    .bss : { *(.bss*) *(COMMON) }
}
