#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums)
    {
        vector<int> copy(nums);

        sort(copy.begin(), copy.end());

        if(copy[copy.size() - 1] >= 2 * (copy[copy.size() - 2]))
        {
            for(int i = 0; i <= copy.size(); ++i)
            {
                if(nums[i] == copy[copy.size() - 1])
                {
                    return i;
                }
            }
        }

        return -1;
    }
};