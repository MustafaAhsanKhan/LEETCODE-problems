#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int i = 0;

        int n = nums.size();

        for(int j = n - 1; j >= i;)
        {
            if(nums[i] == val)
            {
                if(nums[j] != val)
                {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                    i++;
                    j--;
                }
                else
                {
                    j--;
                }
            }
            else
            {
                i++;
            }
        }

        return i + 1;
    }
};