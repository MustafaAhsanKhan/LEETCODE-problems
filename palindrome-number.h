#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
        {
            return false;
        }

        int length = 0;

        for(int i = 0; ; ++i)
        {
            if(x / 10 != 0)
            {
                length++;
            }
            else
            {
                break;
            }
        }

        cout << length;

        return true;
    }
};