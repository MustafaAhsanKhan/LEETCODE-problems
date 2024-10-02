#include <iostream>
using namespace std;
#include <stack>

class Solution {
public:
    string removeStars(string s)
    {
        stack<char> s1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != '*')
            {
                s1.push(s[i]);
            }
            else if (!s1.empty())
            {
                s1.pop();
            }
        }

        string result = "";
        while (!s1.empty())
        {
            result += s1.top();
            s1.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};