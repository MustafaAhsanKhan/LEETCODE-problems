#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations)
    {
        stack<int> s1;
        int total = 0;

        for (int i = 0; i < operations.size(); ++i)
        {
            if (operations[i] == "+")
            {
                int top = s1.top();
                s1.pop();
                int newTop = s1.top() + top;
                s1.push(top); // Push back the first top value
                s1.push(newTop);
            }
            else if (operations[i] == "D")
            {
                s1.push(2 * s1.top());
            }
            else if (operations[i] == "C")
            {
                s1.pop();
            }
            else
            {
                s1.push(stoi(operations[i]));
            }
        }

        // Calculate the total
        while (!s1.empty())
        {
            total += s1.top();
            s1.pop();
        }

        return total;
    }
};
