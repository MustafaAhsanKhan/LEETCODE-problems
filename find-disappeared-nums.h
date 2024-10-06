#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        unordered_set<int> numSet;
        vector<int> result;
        
        // Insert all elements of the array into the set
        for (int num : nums)
        {
            numSet.insert(num);
        }
        
        // Iterate over the range from 0 to n
        for (int i = 1; i <= nums.size(); ++i)
        {
            // If i is not in the set, it's the missing number
            if (numSet.find(i) == numSet.end())
            {
                result.push_back(i);
            }
        }
        
        return result;
    }
};