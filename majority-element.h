#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> freqMap;

        // Build the frequency map
        for (int value : nums)
        {
            freqMap[value]++;
        }

        for (const auto& pair : freqMap)
        {
            if (pair.second > nums.size() / 2)
            {
                return pair.first;
            }
        }
        return 0;
    }
};