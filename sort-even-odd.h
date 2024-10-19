#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> evenIndexedElements;
        vector<int> oddIndexedElements;
        
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                evenIndexedElements.push_back(nums[i]);
            else
                oddIndexedElements.push_back(nums[i]);
        }

        sort(evenIndexedElements.begin(), evenIndexedElements.end());
        sort(oddIndexedElements.begin(), oddIndexedElements.end(), greater<int>());

        int evenIdx = 0;
        int oddIdx = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                nums[i] = evenIndexedElements[evenIdx++];
            else
                nums[i] = oddIndexedElements[oddIdx++];
        }

        return nums;
    }
};