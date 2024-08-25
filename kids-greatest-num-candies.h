#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        vector<bool> result(candies.size());

        int highest = candies[0];  // We will compare all others to this

        for(int i = 1; i < candies.size(); ++i)
        {
            if(candies[i] > highest)
            {
                highest = candies[i];
            }
        }

        for(int i = 0; i < candies.size(); ++i)
        {
            
            if(candies[i] + extraCandies >= highest)
            {
                result[i] = true;
            }
            else
            {
                result[i] = false;
            }
        }

        return result;
    }
};