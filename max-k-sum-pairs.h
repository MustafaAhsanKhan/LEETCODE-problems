#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxOperations(vector<int>& nums, int k)
    {
        int ops = 0;

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        while(left < right)
        {
            int sum = nums[left] + nums[right];

            if(sum == k)  // Valid pair found
            {
                ops++;
                left++;
                right--;
            }
            else if(sum < k)
            {
                left++;
            }
            else if(sum > k)
            {
                right--;
            }
        }

        return ops;

    }
};