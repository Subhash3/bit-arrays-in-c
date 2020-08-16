#include <stdio.h>
#include <stdlib.h>
#include "helperFunctions.h"

void stringReverseInPlace(char *str, int len)
{
    int i;
    for (i = 0; i < len / 2; i++)
    {
        swap(&str[i], &str[len - i - 1]);
    }

    return;
}

void swap(char *a, char *b)
{
    char tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;

    return;
}