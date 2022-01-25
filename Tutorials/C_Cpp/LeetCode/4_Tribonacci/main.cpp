#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
private:
    int mTribonacciNumbers[38];

public:
    Solution()
    {
        for (int i = 0; i < (sizeof(mTribonacciNumbers)/sizeof(int)); i++)
            mTribonacciNumbers[i] = -1;
    }

    int tribonacci(int n)
    {
        int retval = -1;
        if (n > 2)
        {
            if (mTribonacciNumbers[n] == -1)
            {
                // not memoized; compute.
                retval = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
                // memoize
                mTribonacciNumbers[n] = retval;
            }
            else
            {
                retval = mTribonacciNumbers[n];
            }
        }
        else
        {
            retval = ((0 == n) ? 0 : 1);
        }

        return(retval);
    }
};

int main(void)
{
    int n = 25;
    Solution s;
    cout << "Tribonacci(" << n << ") = " << s.tribonacci(n) << endl;
    return 0;
}