#include <iostream>
#include <unordered_map>
#include <string.h>

using namespace std;

static int *tokenizeArgument(char *str, int *arr_size);
static void printArray(const int *arr, int arr_count, int *mask);
static int productOfElements(const int *arr, int arr_count, int *mask);
static void printAllCombinations(const int *arr, int arr_count, unordered_map<int, int> *umap);
static void combinations(const int *arr, int arr_count, int *mask, int postion, unordered_map<int, int> *umap);

int main(int argc, char **argv)
{
    if (2 == argc)
    {
        printf("Is %s colorful?\n", argv[1]);
        int set_size;
        int *set = tokenizeArgument(argv[1], &set_size);

        unordered_map<int, int> umap;

        printAllCombinations(set, set_size, &umap);

        printf("Colorful.\n");
    }
    else if (2 < argc)
    {
        printf("Too many arguments.\n");
    }
    else
    {
        printf("Syntax: ./ColorfulNumber.exe 234 \n");
    }
}

static int *tokenizeArgument(char *str, int *arr_size)
{
    // count up the numbers in the string
    for (*arr_size = 0; str[*arr_size]; (*arr_size)++)
    {
    }

    int *array = (int *)malloc(sizeof(int) * (*arr_size));

    for (int i = 0; str[i]; i++)
    {
        array[i] = str[i] - '0';
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

static int productOfElements(const int *arr, int arr_count, int *mask)
{
    int productOfElements = 1;
    for (int i = 0; i < arr_count; i++)
    {
        if (1 == mask[i])
            productOfElements *= arr[i];
    }

    return productOfElements;
}

static void printAllCombinations(const int *arr, int arr_count, unordered_map<int, int> *umap)
{
    int *mask = (int *)malloc(arr_count * sizeof(int));
    if (!mask)
    {
        fprintf(stderr, "Error: cant allocate memory");
        exit(1);
    }
    memset(mask, 0, arr_count * sizeof(int));

    combinations(arr, arr_count, mask, 0, umap);

    free(mask);
}

static void combinations(const int *arr, int arr_count, int *mask, int postion, unordered_map<int, int> *umap)
{
    // base condition
    if (postion == arr_count - 1)
    {
        // last element in the array
        // choose it and print it
        mask[postion] = 1;
        printArray(arr, arr_count, mask);
        int p = productOfElements(arr, arr_count, mask);
        printf("product = %d\n", p);
        if (umap->find(p) != umap->end())
        {
            printf("Not Colorful.\n");
            exit(1);
        }
        else
        {
            (*umap)[p] = 1;
        }

        // ignore it
        mask[postion] = 0;
        printArray(arr, arr_count, mask);
        p = productOfElements(arr, arr_count, mask);
        printf("product = %d\n", p);
        if (umap->find(p) != umap->end())
        {
            printf("Not Colorful.\n");
            exit(1);
        }
        else
        {
            (*umap)[p] = 1;
        }

        return;
    }

    // curr element:
    // choose it
    mask[postion] = 1;
    combinations(arr, arr_count, mask, postion + 1, umap);

    // ignore it
    mask[postion] = 0;
    combinations(arr, arr_count, mask, postion + 1, umap);
}