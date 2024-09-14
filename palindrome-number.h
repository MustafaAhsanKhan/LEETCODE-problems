#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x == 0)
        {
            return true;
        }
        if(x < 0 || x % 10 == 0)
        {
            return false;
        }

        int reversed_num = 0;

        while(x > reversed_num)
        {
            int pop = x % 10;
            x = x / 10;

            reversed_num = reversed_num * 10 + pop;
        }

        if(x == reversed_num || x == (reversed_num / 10))
        {
            return true;
        }

        return false;
    }
};