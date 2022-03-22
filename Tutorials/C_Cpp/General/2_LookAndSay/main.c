#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG

static void LookAndSay(char *string, int nIters)
{
    char *inStr = (char *)malloc(strlen(string));
    if (!inStr)
        return;
    char *inStrCopyPtr = inStr;
    strcpy(inStr, string);

    while (nIters)
    {
        int currNum = 0, nextNum = 0;
        int currNumCount = 0;
        int totalStrCount = 0;

        // allocate a new string to store the output (double size)
        char *outStr = (char *)malloc(strlen(inStr) * 2);
        if (!outStr)
            return;

        for (int j = 0; j < strlen(inStr); j++)
        {
            // Read each num from the string and count up until you find a different
            // number
            currNum = inStr[j] - '0';
            currNumCount++;

            nextNum = inStr[j + 1] - '0';

            if (currNum != nextNum)
            {
                // print count and number to new string
                outStr[totalStrCount++] = (char)(currNumCount + '0');
                outStr[totalStrCount++] = (char)(currNum + '0');

                // reset count
                currNumCount = 0;
            }
        }
        // terminate string
        outStr[totalStrCount] = '\0';

        // print outStr
        printf("%s\n", outStr);

        // set inStr to point to the outStr for the next iteration
        inStr = (char *)malloc(totalStrCount);
        strcpy(inStr, outStr);
        free(outStr);
        totalStrCount = 0;

        nIters--;
    }

    free(inStrCopyPtr);
}

int main(void)
{
    LookAndSay("1", 5);

    return 0;
}
