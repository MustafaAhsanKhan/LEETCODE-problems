#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romans = {{'M', 1000}, {'D', 500}, {'C', 100}, 
                                                {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int prev = 0, running_total = 0;

        for (int i = s.length() - 1; i >= 0; --i)
        {
            int curr = romans[s[i]];
            if (prev > curr)
            {
                running_total -= curr;
            }
            else
            {
                running_total += curr;
            }
            prev = curr;
        }

        return running_total;
    }
};