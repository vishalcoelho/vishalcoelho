#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;
class Solution
{
public:
    static string RemoveDuplicateLetters(string s)
    {
        char *stack = new char[s.size() + 1];
        int top = -1;

        int *charHist = new int[26];
        memset(charHist, 0, 26 * sizeof(int));
        for (int i = 0; i < s.size(); i++)
            charHist[s[i] - 'a']++;

        for (int i = 0; i < s.size(); i++)
        {
            char currChar = s[i];
            bool charAlreadyInSolution = false;

            // decrement a character's count each time it is encountered.
            charHist[currChar - 'a']--;

            // check if current char is already in the solution
            for (int p = top; p >= 0; p--)
            {
                if (stack[p] == currChar)
                {
                    charAlreadyInSolution = true;
                    break;
                }
            }

            // if yes, continue to the next loop
            if (charAlreadyInSolution)
            {
                charAlreadyInSolution = false;
                continue;
            }
            else
            {
                // push current char to the top of the stack
                stack[++top] = currChar;

                // if no, check how many elements you can pop off the stack and be able
                // to push the curr char as the new top of the stack. you can only pop off a
                // char if
                // 1. currChar < stack[top]
                // 2. stack[top] has a count > 1
                for (int p = top - 1; p >= 0; p--)
                {
                    if ((stack[top] < stack[p]) && (charHist[stack[p] - 'a'] > 0))
                    {
                        // can remove the element at p
                        stack[p] = stack[top];
                        top = p;
                        // cout << "Top="<<stack[top]<<" ";
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        // Terminate the stack...as a string
        stack[top + 1] = '\0';

        // cout << (string)stack << endl;
        return ((string)stack);
    }

private:
};

int main(void)
{
    cout << "cdabcdabc is reduced to " << Solution::RemoveDuplicateLetters("cdabcdabc") << endl;
    cout << "xayqdegabc is reduced to " << Solution::RemoveDuplicateLetters("xayqdegabc") << endl;
    cout << "pqartpquiopk is reduced to " << Solution::RemoveDuplicateLetters("pqartpquiopk") << endl;
}