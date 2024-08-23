#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int len1 = word1.length();
        int len2 = word2.length();


        char* new_str = new char[len1 + len2 + 1];

        if(len1 > len2)
        {
            for(int i = 0, j = 0; i < len1; ++i)
            {
                if(i >= len2)
                {
                    new_str[i + len2] = word1[i];
                }
                else
                {
                    new_str[j] = word1[i];
                    new_str[j + 1] = word2[i];
                    j = j + 2;
                }
            }
        }
        else
        {
            for(int i = 0, j = 0; i < len2; ++i)
            {
                if(i >= len1)
                {
                    new_str[i + len1] = word2[i];
                    
                }
                else
                {
                    new_str[j] = word1[i];
                    new_str[j + 1] = word2[i];
                    j = j + 2;
                }
            }
        }
        new_str[len1 + len2] = '\0';

        return new_str;
    }
};

//#include "merge-strings-alternatively.h"

// int main()
// {
//     Solution foo;
//     cout << foo.mergeAlternately("abcdef", "123");

//     return 0;
// }