#include <stdio.h>
#include "bitManipulations.h"
#include "helperFunctions.h"

int main()
{
    printf("\t------- USAGE ----------\n");
    printf("Bytes are ordered using little endian byte ordering.\n");
    printf("For eg. if your bit array is of length 19, its indices look like this: \n");
    printf("\x1b[33m\t8,7,6,5,4,3,2,1 - 16,15,14,13,12,11,10,9 - 19,18,17\x1b[0m\n");
    printf("Notice that in the above example, the bytes are separated using '-'\n\t and bits of each byte are separated using ','\n");
    printf("\t------------------------\n\n");
    printf("Press enter to continue... ");
    scanf("%*c");

    BitArray *bitArray = NULL;
    int bitsNeeded = 10, choice = -1, bitIndex;

    bitArray = initBitArrayWithInteger(&bitArray, bitsNeeded, 5);
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