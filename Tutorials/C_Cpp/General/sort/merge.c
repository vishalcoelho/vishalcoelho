#include "common.h"
#include "merge.h"

static void merge(int *arr, int *copy, int left, int right);
static void combine(int *arr, int *copy, int left, int mid, int right);

void Sort_merge(int *arr, int arr_size)
{
    int left = 0;
    int right = arr_size - 1;

    int *copy = (int *)malloc((right + 1) * sizeof(int));
    if (NULL == copy)
    {
        fprintf(stderr, "malloc failed");
        exit(1);
    }

    merge(arr, copy, left, right);

    free(copy);
}

static void merge(int *arr, int *copy, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    merge(arr, copy, left, mid);
    merge(arr, copy, mid + 1, right);
    combine(arr, copy, left, mid, right);
}

static void combine(int *arr, int *copy, int left, int mid, int right)
{
    int arr_size = right - left + 1;
    int l_start = left;
    int l_end = mid;
    int r_start = mid + 1;
    int r_end = right;
    right = r_start;

    int k = 0;
    while ((left <= l_end) && (right <= r_end))
    {
        if (arr[left] < arr[right])
        {
            copy[k] = arr[left];
            left++;
        }
        else // (copy[left] >= copy[right])
        {
            copy[k] = arr[right];
            right++;
        }
        k++;
    }

    // left half remaining
    while (left <= l_end)
    {
        copy[k] = arr[left];
        left++;
        k++;
    }

    // right half remaining
    while (right <= r_end)
    {
        copy[k] = arr[right];
        right++;
        k++;
    }

    memcpy(&arr[l_start], copy, arr_size * sizeof(int));
}
