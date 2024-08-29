#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        if(nums.size() < k)
        {
            return 0;
        }

        double sum = 0;
        double max_average = 0;

        for(int i = 0; i < k; ++i)
        {
            sum += nums[i];
        }

        max_average = sum / k;

        for(int i = 0; i < nums.size() - k; ++i)
        {
            sum -= nums[i];
            sum += nums[i + k];

            if(sum / k > max_average)
            {
                max_average = sum / k;
            }

        }

        return max_average;
    }
};