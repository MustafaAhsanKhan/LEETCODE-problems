#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int size = nums.size();

        int prod1 = nums[0] * nums[size - 1] * nums[size - 2];
        int prod2 = nums[size - 1] * nums[size - 2] * nums[size - 3];

        if(prod1 > prod2)
        {
            return prod1;
        }
        return prod2;
    }
};