#include <iostream>

using namespace std;

class Solution
{
private:
    // Memoize: A store of preveiously computed values, index from [1]
    // Just an array, not a hash
    int hashMap[46];

public:
    Solution()
    {
        // Init the hash map to -1
        memset(hashMap, -1, sizeof(hashMap));
    }

    int climbStairs(int n)
    {
        int retval;

        if (3 > n)
        {
            // base condition: step 1 - only one way to get to it
            //                 step 2 - two ways to get to it: step + step or a 2-step
            retval = n;
        }
        else
        {
            // only compute if not done previously
            retval = hashMap[n];
            if(-1 == retval)
            {
                // can only get to step n from n-1 or n-2; this is
                // the recurrence relation.
                retval = climbStairs(n - 1) + climbStairs(n - 2);
            }
        }
        // Store for future
        hashMap[n] = retval;
        return (retval);
    }
};

int main(void)
{
    Solution s;
    for (int i = 1; i <= 45; i++)
    {
        cout << "Ways to get to stair #" << i << ": " << s.climbStairs(i) << endl;
    }

    return 0;
}