#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
private:
    // Copy of nums
    vector<int> copy_of_nums;
    // Flag to track if nums has been initialized
    bool isNumsInit;
    // memoize: hash map to store previously computed values
    map<int, int> hashMap;

public:
    Solution(vector<int> aNums) : copy_of_nums(aNums)
                                , isNumsInit(false)
    {
        // member references must be initialized; this constructor
        // will do that in the base initializer list.
    }

    Solution()
    {
        // default constructor.
        isNumsInit = false;
    }

    int dp(int index)
    {
        // 1. index of the house is the state variable.
        int retval = 0;
        if (0 == index)
        {
            // 2. base condition: either at house #0 or #1
            retval = copy_of_nums[0];
        }
        else if (1 == index)
        {
            retval = max(copy_of_nums[0], copy_of_nums[1]);
        }
        else
        {
            map<int, int>::iterator it = hashMap.find(index);
            if(it == hashMap.end())
            {
                // Not memoized. Compute.
                // 2. recurrence relation: dp(i) = max(dp(i-1), nums[i] + dp(i-2))
                //    choice: if we decide to not rob house[i], we have robbed i-1
                //            and are left with loot_from_house[i-1]
                //    choice: if we decide to rob house[i], we get loot_from_house[i]
                //            pluse loot_from_house[i-2]; remmeber, we cant rob house[i-1]
                //            in this case.
                //    Choose the max payout between the two
                retval = max(dp(index - 1), (copy_of_nums[index] + dp(index - 2)));
                // Memoize the max_possible_loot for this house
                hashMap[index] = retval;
            }
            else
            {
                retval = it->second;
            }
        }

        return retval;
    }

    int rob(vector<int> &nums)
    {
        if(false == isNumsInit)
        {
            // Make a copy if its never initialized
            copy_of_nums = nums;
        }

        int retval = -1;

        retval = dp(nums.size() - 1);

        return (retval);
    }
};

int main(void)
{
    vector<int> house_vals = { 2, 7, 9, 3, 1 };
    Solution s(house_vals);
    cout << "Max Loot tonight: " << s.rob(house_vals) << endl;
    return 0;
}