#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define DEBUG

bool OneEditApart(const char *s1, const char *s2)
{
    size_t szS1 = strlen(s1);
    size_t szS2 = strlen(s2);
    int differences = 0;

    if (szS1 == szS2)
    {
        for (int i = 0; i < szS1; i++)
        {
            if (s1[i] != s2[i])
            {
                differences++;
                if (differences > 1)
                    return false;
            }
        }
    }
    else
    {
        if (abs(szS1 - szS2) > 1)
            return false;

        // size imbalances
        if (szS1 > szS2)
        { // s2 smaller
            for (int i = 0, j = 0; i < szS2; i++, j++)
            {
                if (s2[i] != s1[j])
                {
                    differences++;
                    j++;
                }
                if (differences > 2)
                    return false;
            }
        }
        else
        { // s1 smaller
            for (int i = 0, j = 0; i < szS1; i++, j++)
            {
                if (s1[i] != s2[j])
                {
                    differences++;
                    j++;
                }
                if (differences > 2)
                    return false;
            }
        };
    }

    return true;
}

int main(void)
{
    (OneEditApart("cat", "dog") == false) ? printf("false\n") : printf("Error\n");
    (OneEditApart("cat", "cats") == true) ? printf("true\n") : printf("Error\n");
    (OneEditApart("cat", "cut") == true) ? printf("true\n") : printf("Error\n");
    (OneEditApart("cat", "cast") == true) ? printf("true\n") : printf("Error\n");
    (OneEditApart("cat", "at") == true) ? printf("true\n") : printf("Error\n");
    (OneEditApart("cat", "act") == false) ? printf("false\n") : printf("Error\n");

    return 0;
}
