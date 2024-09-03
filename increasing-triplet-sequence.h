#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        for(int i = 0; i < nums.size() - 2; ++i)
        {
            int count = 1;
            int curr_index = i;
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[j] > nums[curr_index])
                {
                    curr_index = j;
                    count++;
                    cout << curr_index << endl;
                    if(count == 3)
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};