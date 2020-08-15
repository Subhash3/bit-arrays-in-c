#include <stdio.h>
#include "bitManipulations.h"

int main()
{
    BitArray *bitArray = NULL;
    int bitsNeeded = 6;

    bitArray = initBitArray(&bitArray, bitsNeeded);

    printBitArray(&bitArray);
    setBit(&bitArray, 0);
    printBitArray(&bitArray);
    setBit(&bitArray, 1);
    printBitArray(&bitArray);
    clearAllBits(&bitArray);
    printBitArray(&bitArray);
    setBit(&bitArray, bitsNeeded - 1);
    printBitArray(&bitArray);
    setAllBits(&bitArray);
    printBitArray(&bitArray);

    return 0;
}