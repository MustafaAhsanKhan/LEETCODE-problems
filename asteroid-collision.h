#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int> s1;

        for (int i = 0; i < asteroids.size(); ++i)
        {
            int val = asteroids[i];

            // Process the asteroid for potential collisions
            while (!s1.empty() && s1.top() > 0 && val < 0)
            {
                if (abs(s1.top()) > abs(val))
                {
                    // The asteroid on the stack is larger and survives, current asteroid is destroyed
                    val = 0;
                    break;
                }
                else if (abs(s1.top()) < abs(val))
                {
                    // The asteroid on the stack is smaller, so it gets destroyed
                    s1.pop();
                }
                else
                {
                    // Both asteroids are the same size, both get destroyed
                    s1.pop();
                    val = 0;
                    break;
                }
            }

            // If the current asteroid survived after all collisions, push it to the stack
            if (val != 0)
            {
                s1.push(val);
            }
        }

        asteroids.clear();
        while(!s1.empty())
        {
            asteroids.push_back(s1.top());
            s1.pop();
        }

        reverse(asteroids.begin(), asteroids.end());

        return asteroids;
    }
};