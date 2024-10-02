#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths are equal, otherwise return false immediately
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenate s with itself
        string doubled = s + s;
        
        // Check if goal is a substring of the doubled string
        return doubled.find(goal)
    }
};

// Shortened code

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         //short
//         return (s.length() == goal.length() && (s+s).find(goal)!=  string::npos);
//     }
// };