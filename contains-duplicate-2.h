#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_set<int> seen;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (seen.find(nums[i]) != seen.end())
            {
                return true;
            }

            seen.insert(nums[i]);

            // Keep the size of the set within the window size of 'k'
            if (seen.size() > k)
            {
                seen.erase(nums[i - k]);  // Remove the element that is out of the window
            }
        }

        return false;
    }
};
