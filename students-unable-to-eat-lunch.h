#include <iostream>
using namespace std;
#include <vector>
#include <queue>
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        queue<int> q1;
        for(int i = 0; i < students.size(); ++i)  // Making the students queue
        {
            q1.push(students[i]);
        }

        bool flag = true;
        int i = 0;
        while(flag)
        {
            if(q1.front() == students[i])
            {
                q1.pop();  // Removing that student
                i++;  // Going to next sandwitch
            }
            else  // Sending student to back of queue
            {
                int temp = q1.front();
                q1.pop();
                q1.push(temp);
            }
        }
    }
};