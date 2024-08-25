#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int x = 0;
        int y = 0;

        int dx = 1;
        int dy = 0;

        vector<int> result(rows * cols);

        // We will update dx and dy when we reach the side/corner of the matrix
        // The formula used to update dx and dy is:
        // temp = dx
        // dx = -dy
        // dy = dx

        for(int i = 0; i < rows * cols; ++i)
        {
            result[i] = matrix[y][x];
            matrix[y][x] = INT32_MIN;

            if (!(0 <= x + dx && x + dx < cols && 0 <= y + dy && y + dy < rows) || matrix[y+dy][x+dx] == INT32_MIN)
            {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }

            x += dx;
            y += dy;
        }

        return result;
    }
};

// #include "spiral-matrix.h"

// int main()
// {
//     vector<vector<int>> VEC = {{1,2,3},{4,5,6},{7,8,9}};

//     vector<int> result;

//     Solution foo;

//     result = foo.spiralOrder(VEC);

//     for (int i = 0; i < result.size(); ++i)
//     {
//         cout << result[i] << " ";
//     }

// }