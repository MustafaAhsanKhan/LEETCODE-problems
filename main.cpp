#include "spiral-matrix.h"

int main()
{
    vector<vector<int>> VEC = {{1,2,3},{4,5,6},{7,8,9}};

    vector<int> result;

    Solution foo;

    result = foo.spiralOrder(VEC);

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }

}