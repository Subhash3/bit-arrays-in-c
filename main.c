#include <stdio.h>
#include "bitManipulations.h"

int main()
{
    BitArray *bitArray = NULL;
    int bitsNeeded = 20;
    bitArray = initBitArray(bitArray, bitsNeeded);

    printBitArray(bitArray);
    setBit(bitArray, 19);
    printBitArray(bitArray);
    setBit(bitArray, 5);
    printBitArray(bitArray);
    setBit(bitArray, 0);
    printBitArray(bitArray);
    setBit(bitArray, 7);
    printBitArray(bitArray);
    toggleBit(bitArray, 7);
    printBitArray(bitArray);
    toggleBit(bitArray, 7);
    printBitArray(bitArray);
    clearBit(bitArray, 5);
    printBitArray(bitArray);
    setAllBits(bitArray);
    printBitArray(bitArray);
    clearAllBits(bitArray);
    printBitArray(bitArray);

    return 0;
}