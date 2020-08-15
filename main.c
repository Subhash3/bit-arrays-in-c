#include <stdio.h>
#include "bitManipulations.h"

int main()
{
    BitArray *bitArray = NULL;
    int bitsNeeded = 6, choice = -1, bitIndex;

    bitArray = initBitArray(&bitArray, bitsNeeded);
    printBitArray(&bitArray);

    while (1)
    {
        printf("1. Set a bit.\n");
        printf("2. Clear a bit.\n");
        printf("3. Set all bits.\n");
        printf("4. Clear all bits.\n");
        printf("5. Equivalent decimal.\n");
        printf("6. Exit\n>> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\t Which bit to set?: ");
            scanf("%d", &bitIndex);
            setBit(&bitArray, bitIndex);
            printBitArray(&bitArray);
            break;
        case 2:
            printf("\t Which bit to clear?: ");
            scanf("%d", &bitIndex);
            clearBit(&bitArray, bitIndex);
            printBitArray(&bitArray);
            break;
        case 3:
            setAllBits(&bitArray);
            printBitArray(&bitArray);
            break;
        case 4:
            clearAllBits(&bitArray);
            printBitArray(&bitArray);
            break;
        case 5:
            printf("%d\n", equivalentDecimal(&bitArray));
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Choice!\n");
            break;
        }
    }

    printBitArray(&bitArray);
    printf("%d\n", equivalentDecimal(&bitArray));
    setBit(&bitArray, 0);
    printBitArray(&bitArray);
    // setBit(&bitArray, 1);
    // printBitArray(&bitArray);
    // clearAllBits(&bitArray);
    // printBitArray(&bitArray);
    setBit(&bitArray, bitsNeeded - 1);
    printBitArray(&bitArray);
    // printf("%d\n", equivalentDecimal(&bitArray));
    // setAllBits(&bitArray);
    // printBitArray(&bitArray);

    return 0;
}