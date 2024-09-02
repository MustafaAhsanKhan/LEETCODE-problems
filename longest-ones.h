#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int longest_len = 0;
        int max_0 = 0;
        // Right and left pointers
        int r = 0;
        int l = 0;

        for(; r < nums.size(); ++r)
        {
            int curr_len = 0;
            if(nums[r] == 0)
            {
                max_0++;
                //curr_len++;
            }

            while(max_0 > k)
            {
                if(nums[l] == 0)
                {
                    max_0--;
                }
                l++;
                //curr_len--;
            }

            curr_len = r - l + 1;

            if(curr_len > longest_len)
            {
                longest_len = curr_len;
            }
        }

        return longest_len;
    }
};