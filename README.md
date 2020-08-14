### Bit Manipulations in C

#### Bit array structure:
```c
struct  BitArray
{
	int  bitsNeeded;
	int  arraySize;
	unsigned  int  array[MAX_BIT_ARRAY_SIZE];
};
typedef  struct  BitArray  BitArray;
```
#### Usage
##### Create a BitArray object
```c
BitArray *bitArray =  NULL;
```
##### Initialize the bit array
```c
// Function Prototype
BitArray  *initBitArray(BitArray  *bitArr,  int  bitsNeeded);

// Eg.
int bitsNeeded = 10; // No. of bits you want to work with
bitArray =  initBitArray(bitArray, bitsNeeded);
```
##### Bit Operations
```c
bool  setBit(BitArray  *bitArr,  int  k);
/* 
  Sets the (k-1)th bit (to 1). 
  Returns true on success and false on failure.
*/

bool  clearBit(BitArray  *bitArr,  int  k);
/* 
  Clears the (k-1)th bit (makes it 0).
  Returns true on success and false on failure.
*/

bool  isBitSet(BitArray  *bitArr,  int  k);
/*
  Checks of the (k-1)th bit is set(1) or not(0).
  Returns true if set and false otherwise.
*/

void  printBitArray(BitArray  *bitArr);
/*
  Prints the bit array as a binary string (of 1s and 0s).
*/

void  clearAllBits(BitArray  *bitArr)
/*
  Clears all the bits of the bit array.
*/

void  setAllBits(BitArray  *bitArr);
/*
  Sets all the bits of the bit array.
*/
```
