#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        bool f1 = false;

        int size = 0;

        for(int i = s.length() - 1; i >= 0; --i)
        {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                f1 = true;
                size++;
            }
            else if(f1 == true && s[i] == ' ')
            {
                return size;
            }
        }

        return size;
    }
};