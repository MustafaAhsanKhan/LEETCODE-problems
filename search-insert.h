#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int size = nums.size();
        for(int i = 0; i < size - 1; ++i)
        {
            if(nums[i] == target)
            {
                return i;
            }
            else if(nums[i] < target && nums[i + 1] > target)
            {
                return i + 1;
            }
        }

        if(target > nums[size - 1])
        {
            return size;
        }
        else if(target == nums[size - 1])
        {
            return size - 1;
        }
        else
        {
            return 0;
        }
    }
};

// A better solution

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int n = nums.size();
//         int last = nums[n-1];
//         if(target>last){
//             return n;
//         }
//         for(int i = 0; i<nums.size(); i++){
//             if(nums[i]==target){
//                 return i;
//             }
//             if(nums[i]>target){
//                 return i;
//             }
//         }
//         return n;
//     }
// };