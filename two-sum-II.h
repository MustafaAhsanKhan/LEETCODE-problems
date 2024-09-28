#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> result;
        for(int i = 0, j = numbers.size() - 1; i < j;)
        {
            int sum = numbers[i] + numbers[j];
            if(sum == target)
            {
                result.push_back(i + 1);
                result.push_back(j + 1);
                return result;
            }
            else if(sum > target)
            {
                j--;
            }
            else  // sum < target
            {
                i++;
            }
            
        }
        return result;
    }
};