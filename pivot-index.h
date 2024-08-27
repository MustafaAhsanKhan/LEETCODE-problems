#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int pivotIndex(vector<int>& nums)
    {
        for(int i = 0; i < nums.size(); ++i)
        {
            int left_sum = 0;
            int right_sum = 0;

            for(int j = 0; j < i; ++j)
            {
                left_sum += nums[j];
            }

            for(int j = nums.size() - 1; j > i; --j)
            {
                right_sum += nums[j];
            }

            if(left_sum == right_sum)
            {
                return i;
            }
        }

        return -1;
    }
};

// A much better solution

// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int totalSum = 0, leftSum = 0;

//         // Calculate the total sum of the array
//         for(int num : nums) {
//             totalSum += num;
//         }

//         // Traverse the array and check for the pivot index
//         for(int i = 0; i < nums.size(); i++) {
//             // Check if the current index is the pivot index
//             if(leftSum == totalSum - leftSum - nums[i]) {
//                 return i;
//             }
//             // Update the left sum for the next index
//             leftSum += nums[i];
//         }

//         // If no pivot index is found, return -1
//         return -1;
//     }
// };