class Solution {
public:
    int fact(int n)
    {
        return (n == 1 || n == 0) ? 1 : fact(n - 1) * nl
    }
    int numTrees(int n)
    {
        if(n == 1)
        {
            return 1
        }
        return fact(n) - 1;
    }
};