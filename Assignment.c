/*
 * main.c
 *
 *  Created on: 2 Feb 2024
 *      Author: UIDAESL101
 */
/*write a C program , by considering user input as perform below operation for 8 bit data with  4th bit to be manipulated as follows:

press 1 --> set a bit

press 2 --> clear a bit

press 3 --> Toggle a bit

press 4 --> Nibble swapping
*/
#include<stdio.h>
typedef unsigned char uint8;
typedef signed int sint32;
uint8 setBit(uint8 byte, sint32 bitNumber);
uint8 clearBit(uint8 byte, sint32 bitNumber);
uint8 toggleBit(uint8 byte, sint32 bitNumber);
uint8 nibbleSwap(uint8 byte);
int main() {
    uint8 data;
    sint32 choice;
    setbuf(stdout,NULL);
    // Taking user input
    printf("Enter an 8-bit data in hexadecimal:\n");
    scanf("%X", &data);
    setbuf(stdout,NULL);
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

    // Display the updated data
    printf("Updated data: %X\n", data);

    return 0;
}
uint8 setBit(uint8 byte, sint32 bitNumber) {
    return byte | (1 << bitNumber);
}

uint8 clearBit(uint8 byte, sint32 bitNumber) {
    return byte & ~(1 << bitNumber);
}

uint8 toggleBit(uint8 byte, sint32 bitNumber) {
    return byte ^ (1 << bitNumber);
}

uint8 nibbleSwap(uint8 byte) {
    return ((byte & 0x0F) << 4) | ((byte & 0xF0) >> 4);
}

