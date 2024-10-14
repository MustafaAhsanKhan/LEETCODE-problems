#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        
        int n = nums.size();
        vector<int> result(n);

        int prefix = 1;
        // Prefix sum
        for(int i = 0; i < n; ++i)
        {
            result[i] = prefix;
            prefix = prefix * nums[i];
        }

        int postfix = 1;
        // Postfix sum
        for(int i = n - 1; i >= 0; --i)
        {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }

        return result;
    }
};