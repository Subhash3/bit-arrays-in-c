### Bit Manipulations in C

#### Bit array structure:
```c
struct BitArray
{
    int bitsNeeded;
    int arraySize;
    unsigned int array[]; // Flexible Array
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
BitArray *initBitArray(BitArray **bitArr, int bitsNeeded);
/*
  Creates a bit array.
  Returns a pointer to the newly created BitArray object on success and NULL on failure.
*/


BitArray *initBitArrayWithInteger(BitArray **bitArr, int bitsNeeded, int integer);
/*
  Creates a bit array.
  Returns a BitArray object(with each byte set to integer) on success and NULL on failure.
  If the provided integer doens't fit within the specified bits, then the most significant bits will be neglected.'
*/

// Eg.
int bitsNeeded = 10; // No. of bits you want to work with
bitArray =  initBitArray(&bitArray, bitsNeeded);

    OR
num = 5
bitArray =  initBitArrayWithInteger(&bitArray, bitsNeeded, num);
```
##### Bit Operations
```c
bool setBit(BitArray **bitArr, int k);
/* 
  Sets the (k-1)th bit (to 1). 
  Returns true on success and false on failure.
*/

bool clearBit(BitArray **bitArr, int k);
/* 
  Clears the (k-1)th bit (makes it 0).
  Returns true on success and false on failure.
*/

bool isBitSet(BitArray **bitArr, int k);
/*
  Checks of the (k-1)th bit is set(1) or not(0).
  Returns true if set and false otherwise.
*/

bool toggleBit(BitArray **bitArr, int k);
/* 
  Toggles the (k-1)th bit (makes it 0 if 1 and 1 if 0)
  Returns true on success and false on failure.
*/

void printBitArray(BitArray **bitArr);
/*
  Prints the bit array as a binary string (of 1s and 0s).
*/

void clearAllBits(BitArray **bitArr);
/*
  Clears all the bits of the bit array.
*/

void setAllBits(BitArray **bitArr);
/*
  Sets all the bits of the bit array.
*/

int equivalentDecimal(BitArray **bitArr);
/*
  Returns an equivalent decimal to the bit array.
*/
Check main.c file for usage.

###### Feel free to contribute and open any issues.
```
