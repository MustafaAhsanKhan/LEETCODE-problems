#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
        int first = INT_MAX, second = INT_MAX;

        for (int n : nums)
        {
            if (n <= first)
            {
                first = n;  //  smallest element
            }
            else if (n <= second)
            {
                second = n;  // second smallest element
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};
