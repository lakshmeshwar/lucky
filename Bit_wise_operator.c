//header.h

#ifndef HEADER_H
#define HEADER_H

typedef unsigned char uchar;
typedef signed int sint32;
uchar setBit(uchar byte, sint32 bitNumber);
uchar clearBit(uchar byte, sint32 bitNumber);
uchar toggleBit(uchar byte, sint32 bitNumber);
uchar nibbleSwap(uchar byte);

#endif  // HEADER_H
*********************************************
//main.c
#include <stdio.h>
#include "header.h"

int main() {
    uchar data;
    sint32 choice;

    // Taking user input
    printf("Enter an 8-bit data in hexadecimal (e.g., 0x0A):\n");
    scanf("%hhX", &data);

    // Display menu
    printf("Menu:\n");
    printf("1. Set a bit\n");
    printf("2. Clear a bit\n");
    printf("3. Toggle a bit\n");
    printf("4. Nibble swapping\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            data = setBit(data, 4);
            break;

        case 2:
            data = clearBit(data, 4);
            break;

        case 3:
            data = toggleBit(data, 4);
            break;

        case 4:
            data = nibbleSwap(data);
            break;

        default:
            printf("Invalid choice\n");
            return 1;
    }

    // Display the updated data in hexadecimal format
    printf("Updated data: %X\n", data);

    return 0;
}
*************************************************************
//bit_manipulation.c
#include "header.h"

uchar setBit(uchar byte, sint32 bitNumber) {
    return byte | (1 << bitNumber);
}

uchar clearBit(uchar byte, sint32 bitNumber) {
    return byte & ~(1 << bitNumber);
}

uchar toggleBit(uchar byte, sint32 bitNumber) {
    return byte ^ (1 << bitNumber);
}

uchar nibbleSwap(uchar byte) {
    return ((byte & 0x0F) << 4) | ((byte & 0xF0) >> 4);
}
