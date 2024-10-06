#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> set1, set2;
        vector<int> result;

        for(int num : nums1)
        {
            set1.insert(num);
        }

        for(int num : nums2)
        {
            set2.insert(num);
        }

        for(int num : set2)
        {
            if(set1.find(num) != set1.end())
            {
                result.push_back(num);
            }
        }

        return result;
    }
};