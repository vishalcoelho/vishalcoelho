#include "common.h"

void printArray(const int *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}