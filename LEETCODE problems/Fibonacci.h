#pragma once
class Fibonacci
{
public:
	int fib(int n)
	{
        if (n == 0)
        {
            return n;
        }
        if (n == 1 || n == 2)
        {
            return 1;
        }
        int prev = 0, curr = 1;
        for (int i = 2; i <= n; i++)
        {
            curr = prev + curr;
            prev = curr - prev;
        }
        return curr;
	}
};

//#include "Fibonacci.h"
//int main()
//{
//    Fibonacci fib;
//    cout << fib.fib(6);
//    return 0;
//}