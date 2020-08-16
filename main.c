#include <stdio.h>
#include "bitManipulations.h"
#include "helperFunctions.h"

int main()
{
    BitArray *bitArray = NULL;
    int bitsNeeded = 12, choice = -1, bitIndex;

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
            printf("\t>> Which bit to set?: ");
            scanf("%d", &bitIndex);
            setBit(&bitArray, bitIndex - 1);
            break;
        case 2:
            printf("\t>> Which bit to clear?: ");
            scanf("%d", &bitIndex);
            clearBit(&bitArray, bitIndex - 1);
            break;
        case 3:
            setAllBits(&bitArray);
            break;
        case 4:
            clearAllBits(&bitArray);
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
        printBitArray(&bitArray);
    }

    return 0;
}