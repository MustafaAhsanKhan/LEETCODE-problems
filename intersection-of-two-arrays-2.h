#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> freqMap;
        vector<int> result;

        // Step 1: Count the frequency of each element in nums1
        for (int num : nums1)
        {
            freqMap[num]++;
        }

        // Step 2: Iterate through nums2 and find common elements
        for (int num : nums2)
        {
            // If the element exists in the map and its count is greater than 0
            if (freqMap[num] > 0)
            {
                result.push_back(num);  // Add it to the result
                freqMap[num]--;  // Decrease the count in the map
            }
        }

        return result;
    }
};