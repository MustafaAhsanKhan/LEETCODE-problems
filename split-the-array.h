#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums)
    {
        unordered_map<int, int> freqMap;

        // Build the frequency map
        for (int value : nums)
        {
            freqMap[value]++;
        }

        for (const auto& pair : freqMap)
        {
            if (pair.second > 2)
            {
                return false;
            }
        }
        return true;
    }
};