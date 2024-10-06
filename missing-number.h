#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        unordered_set<int> numSet;
        
        // Insert all elements of the array into the set
        for (int num : nums)
        {
            numSet.insert(num);
        }
        
        // Iterate over the range from 0 to n
        for (int i = 0; i <= nums.size(); ++i)
        {
            // If i is not in the set, it's the missing number
            if (numSet.find(i) == numSet.end())
            {
                return i;
            }
        }
        
        return -1;
    }
};