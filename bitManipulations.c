#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "bitManipulations.h"

int getBitArraySize(int bitsNeeded)
{
    return bitsNeeded / sizeof(int);
}

BitArray *initBitArray(BitArray *bitArr, int bitsNeeded)
{
    int arrSize = getBitArraySize(bitsNeeded);
    int i;

    BitArray *temp = malloc(sizeof(BitArray *) + arrSize * sizeof(int));
    if (!temp)
    {
        return NULL;
    }
    bitArr = (BitArray *)temp;
    bitArr->bitsNeeded = bitsNeeded;
    bitArr->arraySize = arrSize;

    for (i = 0; i < arrSize; i++)
    {
        bitArr->array[i] = 0;
    }

    return bitArr;
}

bool setBit(BitArray *bitArr, int k)
{
    if (k >= bitArr->bitsNeeded)
    {
        return false;
    }
    bitArr->array[k / SIZE_OF_INT_IN_BITS] |= (1 << (k % SIZE_OF_INT_IN_BITS));

    return true;
}

bool clearBit(BitArray *bitArr, int k)
{
    if (k >= bitArr->bitsNeeded)
    {
        return false;
    }
    bitArr->array[k / SIZE_OF_INT_IN_BITS] &= ~(1 << (k % SIZE_OF_INT_IN_BITS));

    return true;
}

bool isBitSet(BitArray *bitArr, int k)
{
    if (k >= bitArr->bitsNeeded)
    {
        return false;
    }
    return ((bitArr->array[k / SIZE_OF_INT_IN_BITS] & (1 << (k % SIZE_OF_INT_IN_BITS))) != 0);
}

bool toggleBit(BitArray *bitArr, int k)
{
    if (k >= bitArr->bitsNeeded)
    {
        return false;
    }
    bitArr->array[k / SIZE_OF_INT_IN_BITS] ^= (1 << (k % SIZE_OF_INT_IN_BITS));
    return true;
}

void printBitArray(BitArray *bitArr)
{
    int i, size = bitArr->bitsNeeded;
    for (i = 0; i < size; i++)
    {
        printf((isBitSet(bitArr, i)) ? "1" : "0");
        fflush(NULL); // flushing must be done 'cuz we're not using \n
    }
    printf("\n");

    return;
}

void clearAllBits(BitArray *bitArr)
{
    int i, size = bitArr->bitsNeeded;
    for (i = 0; i < size; i++)
    {
        clearBit(bitArr, i);
    }

    return;
}
void setAllBits(BitArray *bitArr)
{
    int i, size = bitArr->bitsNeeded;
    for (i = 0; i < size; i++)
    {
        setBit(bitArr, i);
    }

    return;
}