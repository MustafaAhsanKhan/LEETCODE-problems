#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s)
    {
        stack<int> s1;
        int curr = 0;
        char op = '+';
        
        for(int i = 0; i < s.length(); ++i)
        {
            if(isdigit(s[i]))
            {
                curr = (curr * 10) + (s[i] - '0');
            }

            if((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1)
            {
                switch (op)
                {
                    int temp;
                    case '+':
                        s1.push(curr);
                        break;
                    case '-':
                        s1.push(-curr);
                        break;
                    case '*':
                        temp = s1.top();
                        s1.pop();
                        s1.push(temp * curr);
                        break;
                    case '/':
                        temp = s1.top();
                        s1.pop();
                        s1.push(temp / curr);
                        break;
                    
                    default:
                        break;
                }
                op = s[i]; // Update the operator for the next number
                curr = 0;   // Reset curr for the next number
            }
        }

        // Calculate the result from the stack
        int sum = 0;
        while(!s1.empty())
        {
            sum += s1.top();
            s1.pop();
        }

        return sum;
    }
};
