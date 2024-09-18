#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        if(s.empty())
        {
            return 0;
        }

        string cleaned = "";
        for(int i = 0; i < s.length(); ++i)
        {
            if(isalnum(s[i]))
            {
                cleaned += tolower(s[i]);
            }
        }
        int size = cleaned.length();
        cout << size;

        for(int i = 0; i < size / 2; ++i)
        {
            if(cleaned[i] != cleaned[size - i - 1])
            {
                return 0;
            }
        }

        return 1;
    }
};