#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        if(t.length() < s.length())
        {
            return false;
        }
        else if(s.length() == 0 && t.length() == 0)
        {
            return true;
        }
        
        // i is used to traverse t
        // j is used to traverse s

        for(int i = 0, j = 0; i < t.length();)
        {
            if(t[i] == s[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
            if(j == s.length())
            {
                return true;
            }
        }

        return false;
    }

};