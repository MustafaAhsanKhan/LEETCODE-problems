#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); ++i)
        {
            int index = 0;
            bool flag = false;
            while(nums2[index] != nums1[i])
            {
                ++index;
            }

            for(index; index < nums2.size(); ++index)
            {
                if(nums2[index] > nums1[i])
                {
                    ans.push_back(nums2[index]);
                    flag = true;
                    break;
                }
            }

            if(!flag)
            {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};