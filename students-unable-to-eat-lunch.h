#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        queue<int> q1;
        for(int i = 0; i < students.size(); ++i)  // Making the students queue
        {
            q1.push(students[i]);
        }

        int i = 0;  // Sandwich index
        int rotations = 0;  // Counter for unsuccessful attempts
        
        while(!q1.empty() && rotations < q1.size())  // Continue until no progress
        {
            if(q1.front() == sandwiches[i])  // Student takes sandwich
            {
                q1.pop();  // Remove student from queue
                i++;  // Move to the next sandwich
                rotations = 0;  // Reset unsuccessful attempts counter
            }
            else  // Student goes to the back of the queue
            {
                int temp = q1.front();
                q1.pop();
                q1.push(temp);
                rotations++;  // Increment unsuccessful attempts
            }
        }

        return q1.size();  // Remaining students unable to eat
    }
};
