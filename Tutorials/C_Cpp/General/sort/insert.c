#include "common.h"
#include "insert.h"

static void insertAboveIthPosition(int *arr, int arr_size, int i);

void Sort_insert(int *arr, int arr_size)
{
    int i = 1;
    while (i < arr_size)
    {
        insertAboveIthPosition(arr, arr_size, i);
        i++;
    }
}

static void insertAboveIthPosition(int *arr, int arr_size, int i)
{
    int j = i - 1;
    int key = arr[i];

    // check all values above the key (element at i) for a place to insert it.
    // All elements > than the key should be moved down one.
    while ((j >= 0) && (arr[j] > key))
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}