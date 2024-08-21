#pragma once
class ClimbingStairs
{
public:
    int climbingStairs(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++)
        {
            curr = prev + curr;
            prev = curr - prev;
        }
        return curr;
    }
};

//#include "ClimbingStairs.h"
//int main()
//{
//	ClimbingStairs cs;
//	cout << cs.climbingStairs(2);
//	return 0;
//}