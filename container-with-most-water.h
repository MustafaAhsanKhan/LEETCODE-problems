#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maxArea(vector<int> height)
    {
        int area = 0;
        for(int i = 0, j = height.size() - 1; i < j;)
        {
            if(height[i] > height[j])
            {
                if((height[j] * (j - i)) > area)
                {
                    area = height[j] * (j - i);
                }
                j--;
            }
            else
            {
                if((height[i] * (j - i)) > area)
                {
                    area = height[i] * (j - i);
                }
                i++;
            }
        }

        return area;
    }
};

// #include "container-with-most-water.h"
// int main()
// {
//     Solution foo;

//     cout << foo.maxArea({1,8,6,2,5,4,8,3,7});
// }