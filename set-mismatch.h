#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums)
    {
        std::map<int, int> freqMap;
        std::vector<int> result(2);

        // Build the frequency map
        for (int value : nums)
        {
            freqMap[value]++;
        }

        int n = nums.size();

        // Traverse numbers from 1 to n
        for (int i = 1; i <= n; ++i)
        {
            if (freqMap[i] == 2)
            {
                result[0] = i;  // Duplicate number
            }
            else if (freqMap[i] == 0)
            {
                result[1] = i;  // Missing number
            }
        }

        return result;  // Return {duplicate, missing}
    }
};

// Custom built hashmap solution 0ms

// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int dup=-1;
//         int mis=-1;
//         int n=nums.size();
//         vector<int> count(n+1 ,0);

//         for(int num :nums){
//             count[num]++ ;
//         }
//         for(int i=1 ;i<=n ;i++){
//             if(count[i] ==0 ){
//                 mis = i ;
//             }
//             else if(count[i] == 2){
//                 dup = i ;
//             }
//         }
//         return {dup , mis};
//     }
// };