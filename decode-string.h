#include <iostream>
using namespace std;
#include <stack>
#include <cctype>
#include <string>

class Solution {
public:
    string decodeString(string s)
    {
        stack<string> s1;  // Stack now stores strings
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ']')
            {
                s1.push(string(1, s[i]));  // Push the character as a string
            }
            else
            {
                // Build the substring between the brackets
                string substr = "";
                while (s1.top() != "[")
                {
                    substr = s1.top() + substr;
                    s1.pop();
                }
                s1.pop();  // Pop the '['

                // Build the number before the '['
                string k = "";
                while (!s1.empty() && isdigit(s1.top()[0]))
                {
                    k = s1.top() + k;
                    s1.pop();
                }

                // Repeat the substring 'k' times
                string result = "";
                for (int j = 0; j < stoi(k); ++j)
                {
                    result += substr;
                }

                // Push the repeated result back onto the stack
                s1.push(result);
            }
        }

        // Convert the contents of the stack to a string
        string finalResult = "";
        while (!s1.empty())
        {
            finalResult = s1.top() + finalResult;
            s1.pop();
        }

        return finalResult;
    }
};