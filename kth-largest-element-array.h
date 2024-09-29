#include <iostream>
using namespace std;
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> maxHeap(nums.begin(), nums.end());

        // Pop elements from the heap k-1 times
        for (int i = 1; i < k; ++i)
        {
            maxHeap.pop();
        }

        // The top element will now be the k-th largest
        return maxHeap.top();
    }
};