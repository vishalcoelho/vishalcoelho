#include "common.h"
#include "quick.h"

static void quick(int *arr, int left, int right);
static int partition(int *arr, int left, int right, int pivot);

void Sort_quick(int *arr, int arr_size)
{
    int left = 0;
    int right = arr_size - 1;

    quick(arr, left, right);
}

static void quick(int *arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    int pivot = arr[mid];

    // sort everything about the pivot values
    int partitionPoint = partition(arr, left, right, pivot);
    quick(arr, left, partitionPoint - 1);
    quick(arr, partitionPoint, right);
}

static int partition(int *arr, int left, int right, int pivot)
{
    while (left <= right)
    {
        // move up on the left till you find a number > pivot
        while (arr[left] < pivot)
            left++;

        // move down on the left till you find a number < pivot
        while (arr[right] > pivot)
            right--;

        // swap, increment indices
        if (left <= right)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    return left;
}