#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n)
    {
        // numTrees(4) = numTrees(0) * numTrees(3) +
        //               numTrees(1) * numTrees(2) +
        //               numTrees(2) * numTrees(1) +
        //               numTrees(3) * numTrees(0) +

        vector<int> num_storage(n + 1, 1);  // Size n+1 with all 1's as the elements

        for(int nodes = 2; nodes < n + 1; ++nodes)
        {
            int total = 0;
            for(int root = 1; root <= nodes; ++root)
            {
                int left = root - 1;        // Number of nodes in left subtree
                int right = nodes - root;   // Number of nodes in right subtree
                total += num_storage[left] * num_storage[right];
            }
            num_storage[nodes] = total;
        }

        return num_storage[n];
    }
};