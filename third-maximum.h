#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <set>

class Solution {
public:
    int thirdMax(vector<int>& nums)
    {
        // Use a set to store only distinct values
        set<int> uniqueNums(nums.begin(), nums.end());

        if (uniqueNums.size() < 3)
        {
            return *uniqueNums.begin();
        }

        // Convert the set back to a max heap
        priority_queue<int> maxHeap(uniqueNums.begin(), uniqueNums.end());

        // Pop the largest two elements
        maxHeap.pop();
        maxHeap.pop();

        // The third maximum
        return maxHeap.top();
    }
};