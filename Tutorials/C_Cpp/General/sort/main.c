#include <stdio.h>
#include <string.h>

#if defined(CMAKE_BUILD)
#include "sort/merge.h"
#include "sort/quick.h"
#include "sort/insert.h"
#include "sort/common.h"
#else
// For VSCODE debugging--I dont know how to add an include folder :-(
#include "merge.h"
#include "quick.h"
#include "insert.h"
#include "common.h"
#endif //  defined(CMAKE_BUILD)

int main(void)
{
    int arrToSortShadow[100];
    // MATLAB: sprintf("%3d, %3d, %3d, %3d, %3d, %3d, %3d, %3d,\n", randi(100, 1, 100))
    int arrToSort[] = {
        47, 62, 14, 84, 45, 93, 78, 22,
        15, 12, 23, 23, 23, 45, 31, 82,
        59, 88, 74, 71, 86, 14, 13, 46,
        29, 68, 24, 21, 61, 62, 100, 99,
        73, 83, 37, 15, 79, 65, 100, 78,
        98, 15, 72, 29, 61, 47, 57, 92,
        42, 9, 77, 38, 49, 30, 62, 85,
        64, 50, 93, 35, 3, 5, 80, 98,
        75, 28, 72, 10, 92, 79, 16, 43,
        96, 19, 28, 6, 15, 9, 72, 8,
        53, 78, 8, 67, 44, 40, 61, 100,
        13, 20, 89, 7, 9, 59, 4, 11,
        40, 54, 22, 39};

    printf("\nUnsorted: ");
    memcpy(arrToSortShadow, arrToSort, sizeof(arrToSort));
    printArray(arrToSort, sizeof(arrToSort) / sizeof(int));
    Sort_merge(arrToSort, sizeof(arrToSort) / sizeof(int));
    printf("\nSorted: ");
    printArray(arrToSort, sizeof(arrToSort) / sizeof(int));

    printf("\nUnsorted: ");
    memcpy(arrToSort, arrToSortShadow, sizeof(arrToSort));
    printArray(arrToSort, sizeof(arrToSort) / sizeof(int));
    Sort_quick(arrToSort, sizeof(arrToSort) / sizeof(int));
    printf("\nSorted: ");
    printArray(arrToSort, sizeof(arrToSort) / sizeof(int));

    printf("\nUnsorted: ");
    memcpy(arrToSort, arrToSortShadow, sizeof(arrToSort));
    printArray(arrToSort, sizeof(arrToSort) / sizeof(int));
    Sort_insert(arrToSort, sizeof(arrToSort) / sizeof(int));
    printf("\nSorted: ");
    printArray(arrToSort, sizeof(arrToSort) / sizeof(int));

    return 0;
}
