#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string reverseVowels(string s)
    {
        bool flag1 = false, flag2 = false;
        char temp = ' ';
        int j = s.length() - 1;

        for(int i = 0; i < s.length(); ++i)
        {
            if(i >= j)
            {
                break;
            }
            if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u')
            {
                for(; j >= 0 ; --j)
                {
                    if((tolower(s[j]) == 'a' || tolower(s[j]) == 'e' || tolower(s[j]) == 'i' || tolower(s[j]) == 'o' || tolower(s[j]) == 'u') && i != j)
                    {
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                        --j;
                        break;
                    }
                    if(j <= i)
                    {
                        break;
                    }
                }
            }
            
        }

        return s;
    }
};

// #include "reverse-vowels-of-string.h"

// int main()
// {
//     Solution foo;

//     cout << foo.reverseVowels("race car");
// }