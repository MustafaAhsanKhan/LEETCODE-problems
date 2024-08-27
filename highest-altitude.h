#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int largestAltitude(vector<int>& gain)
    {
        vector<int> result(gain.size() + 1);

        for(int i = 0; i < gain.size(); ++i)
        {
            result[i + 1] = result[i] + gain[i];
        }
        
        int max = 0;
        for(int i = 1; i < result.size(); ++i)
        {
            if(result[i] > max)
            {
                max = result[i];
            }
        }

        return max;
    }
};