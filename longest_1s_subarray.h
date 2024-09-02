#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int longest_len = 0;
        int max_0 = 0;
        // Right and left pointers
        int r = 0;
        int l = 0;
        int k = 1;
        bool found_zero = false;

        for(; r < nums.size(); ++r)
        {
            int curr_len = 0;
            if(nums[r] == 0)
            {
                max_0++;
                found_zero = true;
            }

            while(max_0 > k)
            {
                if(nums[l] == 0)
                {
                    max_0--;
                }
                l++;
            }

            curr_len = (r - l + 1) - max_0;

            if(curr_len > longest_len)
            {
                longest_len = curr_len;
            }
        }

        if(found_zero)
        {
            return longest_len;
        }
        else
        {
            return nums.size() - 1;
        }
    }
};