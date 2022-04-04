#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

    static inline void swap(int *posA, int *posB)
    {
        int temp = *posA;
        *posA = *posB;
        *posB = temp;
    }

    extern void printArray(const int *arr, int arr_size);

#ifdef __cplusplus
}
#endif

#endif // COMMON_H_