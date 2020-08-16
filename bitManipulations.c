#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bitManipulations.h"
#include "helperFunctions.h"

int SIZE_OF_UINT8_IN_BITS = sizeof(u_int8_t) * 8;
int SIZE_OF_INT_IN_BITS = sizeof(int) * 8;

int getBitArraySize(int bitsNeeded)
{
    float length = (float)bitsNeeded / (float)SIZE_OF_UINT8_IN_BITS;
    float decimalPart = length - (int)length;
    // printf("Bits: %d, arrSize: %f, decimalPart: %f\n", bitsNeeded, length, decimalPart);

    return (decimalPart == 0) ? (int)length : (int)length + 1;
}

BitArray *initBitArray(BitArray **bitArr, int bitsNeeded)
{
    int arrSize = getBitArraySize(bitsNeeded);
    int i;

    BitArray *temp = malloc(sizeof(BitArray *) + arrSize * sizeof(int));
    if (!temp)
    {
        return NULL;
    }
    (*bitArr) = (BitArray *)temp;
    (*bitArr)->bitsNeeded = bitsNeeded;
    (*bitArr)->arraySize = arrSize;

    for (i = 0; i < arrSize; i++)
    {
        (*bitArr)->array[i] = 0;
    }

    // clearAllBits(bitArr);
    return (*bitArr);
}

bool setBit(BitArray **bitArr, int k)
{
    if (k >= (*bitArr)->bitsNeeded)
    {
        return false;
    }
    (*bitArr)->array[k / SIZE_OF_UINT8_IN_BITS] |= (1 << (k % SIZE_OF_UINT8_IN_BITS));

    return true;
}

bool clearBit(BitArray **bitArr, int k)
{
    if (k >= (*bitArr)->bitsNeeded)
    {
        return false;
    }
    (*bitArr)->array[k / SIZE_OF_UINT8_IN_BITS] &= ~(1 << (k % SIZE_OF_UINT8_IN_BITS));

    return true;
}

bool isBitSet(BitArray **bitArr, int k)
{
    if (k >= (*bitArr)->bitsNeeded)
    {
        return false;
    }
    return (((*bitArr)->array[k / SIZE_OF_UINT8_IN_BITS] & (1 << (k % SIZE_OF_UINT8_IN_BITS))) != 0);
}

bool toggleBit(BitArray **bitArr, int k)
{
    if (k >= (*bitArr)->bitsNeeded)
    {
        return false;
    }
    (*bitArr)->array[k / SIZE_OF_UINT8_IN_BITS] ^= (1 << (k % SIZE_OF_UINT8_IN_BITS));
    return true;
}

void printBitArray(BitArray **bitArr)
{
    int i, size = (*bitArr)->bitsNeeded;
    int j = 0;
    u_int8_t byteLength = 8;
    char byte[byteLength + 1];

    for (i = 0; i < (*bitArr)->arraySize; i++)
    {
        printf("   \x1b[34m%d\x1b[0m     ", (*bitArr)->array[i]);
    }

    printf("\n");
    for (i = 0; i < size; i++)
    {
        // printf((isBitSet(bitArr, i)) ? "\x1b[33m1\x1b[0m" : "0");
        byte[j++] = (isBitSet(bitArr, i)) ? '1' : '0';
        if ((i + 1) % byteLength == 0 || i == size - 1)
        {
            byte[j] = '\0';
            stringReverseInPlace(byte, j);
            j = 0;
            printf("%s ", byte);
        }
        fflush(NULL); // flushing must be done 'cuz we're not using \n
    }
    printf("\n");

    return;
}

void clearAllBits(BitArray **bitArr)
{
    int i, size = (*bitArr)->bitsNeeded;
    for (i = 0; i < size; i++)
    {
        clearBit(bitArr, i);
    }

    return;
}
void setAllBits(BitArray **bitArr)
{
    int i, size = (*bitArr)->bitsNeeded;
    for (i = 0; i < size; i++)
    {
        setBit(bitArr, i);
    }

    return;
}

int equivalentDecimal(BitArray **bitArr)
{
    int placeValue = 1, i, decimal = 0;

    for (i = (*bitArr)->bitsNeeded - 1; i >= 0; i--)
    {
        if (isBitSet(bitArr, i))
        {
            decimal += placeValue;
        }
        placeValue *= 2;
    }

    return decimal;
}