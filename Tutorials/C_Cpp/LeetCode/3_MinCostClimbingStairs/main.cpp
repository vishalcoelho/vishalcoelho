#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
private:
    int mLastStep;
    vector<int> mCost;
    map<int, int> mMapOfStepsToAccruedCost;

public:
    Solution()
    {
        mLastStep = 0;
    }

    Solution(vector<int> aCost): mCost(aCost)
                               , mLastStep(0)
    {
    }

    int minCostClimbingStairs(vector<int>& cost) {
        this->mCost = cost;
        mLastStep = cost.size() - 1;

        int costFromStep0 = minCostClimbingStep(0);
        int costFromStep1 = mMapOfStepsToAccruedCost[1];

        return (min(costFromStep0, costFromStep1));
    }

    int minCostClimbingStep(int currStep)
    {
        /* State variable: index of the current step. */
        int retval = -1;
        
        if (currStep == mLastStep)
        {
            /* base condition: cost[N-1] cost[N-2]; N is the total number of 
             * steps. At step N-2 we pay it's cost and then move 2 to the top 
             * of the stairs; at step N-1 we are forced to pay it's cost and 
             * move 1 to the top of the stairs.
             */
            retval = mCost[currStep];
            mMapOfStepsToAccruedCost[currStep] = retval;
        }
        else if (currStep > mLastStep)
        {
            retval = 0;
        }
        else
        {
            map<int, int>::iterator it = mMapOfStepsToAccruedCost.find(currStep);
            if (it == mMapOfStepsToAccruedCost.end())
            {
                /* recurrence condition: The final cost from step i, 
                 * f[i] = cost[i] + min(f[i+1], f[i+2]) 
                 */
                retval = mCost[currStep] + min(minCostClimbingStep(currStep + 1), minCostClimbingStep(currStep + 2));
                /* Memoize the cost incurred at each step. */
                mMapOfStepsToAccruedCost[currStep] = retval;
            }
            else
            {
                retval = it->second;
            }
        }

        return (retval);
    }
};

int main(void)
{
    // vector<int> cost = { 1,100,1,1,1,100,1,1,100,1};
    vector<int> cost = { 10, 15, 20};
    // vector<int> cost = { 1, 100};
    Solution s(cost);
    int minCostClimbingStairs = s.minCostClimbingStairs(cost);
    cout << "Lowest Accrued Cost " << minCostClimbingStairs << endl;
    return 0;
}