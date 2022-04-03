#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int *tokenizeArgument(char *str, int *arr_size);
static void printArray(const int *arr, int arr_count, int *mask);
static void printAllCombinations(const int *arr, int arr_count);
static void combinations(const int *arr, int arr_count, int *mask, int postion);

int main(int argc, char **argv)
{
    if (2 == argc)
    {
        printf("Power set of %s\n", argv[1]);
        int set_size;
        int *set = tokenizeArgument(argv[1], &set_size);
        printAllCombinations(set, set_size);
    }
    else if (2 < argc)
    {
        printf("Too many arguments.\n");
    }
    else
    {
        printf("Syntax: ./PowerSet.exe 2,3,4 \n");
    }
}

static int *tokenizeArgument(char *str, int *arr_size)
{
    // count up the numbers in the string not the commas
    *arr_size = 0;
    for (int i = 0; str[i]; i++)
    {
        // FIXME: assuming single digits
        if (str[i] != ',')
            (*arr_size)++;
    }
    int *array = (int *)malloc(sizeof(int) * (*arr_size));

    /* Get the first token. */
    char *token = strtok(str, ",");
    int i = 0;
    array[i++] = atoi(token);

    while (token != NULL)
    {
        token = strtok(NULL, ",");
        array[i++] = atoi(token);
    }

    return array;
}

static void printArray(const int *arr, int arr_count, int *mask)
{
    printf("[");
    for (int i = 0; i < arr_count; i++)
    {
        if (1 == mask[i])
            printf("%d, ", arr[i]);
    }

    printf("]\n");
}

static void printAllCombinations(const int *arr, int arr_count)
{
    int *mask = (int *)malloc(arr_count * sizeof(int));
    if (!mask)
    {
        fprintf(stderr, "Error: cant allocate memory");
        exit(1);
    }
    memset(mask, 0, arr_count * sizeof(int));

    combinations(arr, arr_count, mask, 0);

    free(mask);
}

static void combinations(const int *arr, int arr_count, int *mask, int postion)
{
    // base condition
    if (postion == arr_count - 1)
    {
        // last element in the array
        // choose it and print it
        mask[postion] = 1;
        printArray(arr, arr_count, mask);

        // ignore it
        mask[postion] = 0;
        printArray(arr, arr_count, mask);

        return;
    }

    // curr element:
    // choose it
    mask[postion] = 1;
    combinations(arr, arr_count, mask, postion + 1);

    // ignore it
    mask[postion] = 0;
    combinations(arr, arr_count, mask, postion + 1);
}