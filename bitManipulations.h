#ifndef __bitManipulations_H__
#define __bitManipulations_H__
#include <stdbool.h>

#define MAX_BIT_ARRAY_SIZE 64
#define SIZE_OF_INT_IN_BITS sizeof(int) * 8

struct BitArray
{
    int bitsNeeded;
    int arraySize;
    unsigned int array[MAX_BIT_ARRAY_SIZE];
};

typedef struct BitArray BitArray;

// Function Prototypes
int getBitArraySize(int bitsNeeded);
/*
  Determines the size of the array given the number of bits needed.
*/

BitArray *initBitArray(BitArray *bitArr, int bitsNeeded);
/*
  Creates a bit array.
  Returns a BitArray object on success and NULL on failure.
*/
bool setBit(BitArray *bitArr, int k);
/* 
  Sets the (k-1)th bit (to 1). 
  Returns true on success and false on failure.
*/

bool clearBit(BitArray *bitArr, int k);
/* 
  Clears the (k-1)th bit (makes it 0).
  Returns true on success and false on failure.
*/

bool isBitSet(BitArray *bitArr, int k);
/*
  Checks of the (k-1)th bit is set(1) or not(0).
  Returns true if set and false otherwise.
*/

bool toggleBit(BitArray *bitArr, int k);
/* 
  Toggles the (k-1)th bit (makes it 0 if 1 and 1 if 0)
  Returns true on success and false on failure.
*/

void printBitArray(BitArray *bitArr);
/*
  Prints the bit array as a binary string (of 1s and 0s).
*/

void clearAllBits(BitArray *bitArr);
/*
  Clears all the bits of the bit array.
*/

void setAllBits(BitArray *bitArr);
/*
  Sets all the bits of the bit array.
*/

#endif