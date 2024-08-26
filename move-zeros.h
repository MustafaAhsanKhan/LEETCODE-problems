#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int index = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
            {
                nums[index] = nums[i];
                index++;
            }
        }

        for(; index < nums.size(); ++index)
        {
            nums[index] = 0;
        }
    }
};

// A better solution

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n=nums.size();
//         int j=0;
//     for(int i=0;i<n;i++){
//         if(nums[i]!=0){
//             swap(nums[i],nums[j]);
//             j++;
//         }

//     }
//     }
// };