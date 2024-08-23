#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> removeDuplicates(vector<int>& arr)
    {
        vector<int> unique_in_arr;

        if (!arr.empty())
        {
            unique_in_arr.push_back(arr[0]);  // Add the first element if arr is not empty
        }

        for(int i = 1; i < arr.size(); ++i)
        {
            bool isDuplicate = false;

            for(int j = 0; j < unique_in_arr.size(); ++j)
            {
                if(arr[i] == unique_in_arr[j])
                {
                    isDuplicate = true;
                    break;  // No need to check further if a duplicate is found
                }
            }

            if (!isDuplicate) {
                unique_in_arr.push_back(arr[i]);
            }
        }

        return unique_in_arr;
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> unique_in_nums1;
        vector<int> unique_in_nums2;

        // Logic to find unique elements in nums1 and nums2
        for(int i = 0; i < nums1.size(); ++i)
        {
            for(int j = 0; j < nums2.size(); ++j)
            {
                if(nums1[i] == nums2[j])
                {
                    break;
                }
                else if(j == nums2.size() - 1)
                {
                    unique_in_nums1.push_back(nums1[i]);
                }
            }
        }

        for(int i = 0; i < nums2.size(); ++i)
        {
            for(int j = 0; j < nums1.size(); ++j)
            {
                if(nums2[i] == nums1[j])
                {
                    break;
                }
                else if(j == nums1.size() - 1)
                {
                    unique_in_nums2.push_back(nums2[i]);
                }
            }
        }

        unique_in_nums1 = removeDuplicates(unique_in_nums1);
        unique_in_nums2 = removeDuplicates(unique_in_nums2);

        
        // Combine the results into a 2D vector
        return {unique_in_nums1, unique_in_nums2};
    }
};