#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int i = digits.size() - 1;
        while(digits[i] == 9)
        {
            if(i == 0 && digits[i] == 9)
            {
                digits[i] = 1;
                int j = digits.size();
                digits.erase(digits.begin() + 1, digits.end());
                for(int k = 1; k <= j; ++k)
                {
                    digits.push_back(0);
                }
                return digits;
            }
            --i;
        }
        if(i >= 0 && digits[i] < 9)
        {
            digits[i] += 1;
            int j = digits.size() - 1;
            digits.erase(digits.begin() + (i + 1), digits.end());
            for(int k = i; k < j; ++k)
            {
                digits.push_back(0);
            }
            return digits;
        }

        digits[i] += 1;

        return digits;
        
    }
};

// A better solution

// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         int n = digits.size();
//         for(int i = n-1; i >= 0; i--){
//             if(digits[i] != 9){
//                 digits[i]++;
//                 break;
//             }
//             digits[i] = 0;
//         }
//         if(digits[0] == 0){
//             vector<int> digits1(n+1, 0);
//             digits1[0] = 1;
//             return digits1;
//         }
//         return digits;
//     }
// };

// #include "plus-one.h"
// int main()
// {
//     Solution foo;

//     vector<int> VEC = {8,8,9};

//     VEC = foo.plusOne(VEC);

//     for (int i : VEC)
//     {
//         cout << i << " ";
//     }
// }