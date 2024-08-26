#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int count = 0;
        int size = flowerbed.size();

        for(int i = 0; i < size; ++i)
        {
            if(flowerbed[i] == 0)
            {
                // Check if the left and right spots are empty or out of bounds
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);

                if(leftEmpty && rightEmpty)
                {
                    flowerbed[i] = 1;
                    count++;
                    
                    // Skip the next spot as it can't be used
                    i++;
                }
                
                if(count >= n)
                {
                    return true;
                }
            }
        }

        return count >= n;
    }
};


// A better solution




// #include "can-place-flowers.h"

// int main()
// {
//     Solution foo;

//     vector<int> VEC = {1,0};

//     cout << foo.canPlaceFlowers(VEC, 1);
// }