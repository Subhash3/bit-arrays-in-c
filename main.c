#include <stdio.h>
#include "bitManipulations.h"

int main()
{
    BitArray *bitArray = NULL;
    int bitsNeeded = 5;
    bitArray = initBitArray(bitArray, bitsNeeded);

    printBitArray(bitArray);
    printf("%d\n", equivalentDecimal(bitArray));
    setBit(bitArray, 0);
    printBitArray(bitArray);
    printf("%d\n", equivalentDecimal(bitArray));
    setBit(bitArray, 1);
    printBitArray(bitArray);
    printf("%d\n", equivalentDecimal(bitArray));
    setBit(bitArray, bitsNeeded - 1);
    printBitArray(bitArray);
    printf("%d\n", equivalentDecimal(bitArray));

    return 0;
}