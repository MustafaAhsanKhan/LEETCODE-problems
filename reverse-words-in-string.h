#include <iostream>
using namespace std;
#include <string>
#include <deque>

class Solution {
public:
    string reverseWords(string s)
    {
        int n = s.length();
        int i = 0;
        string result = "";
        string word;
        while(i < n)
        {
            for(; i < n && s[i] == ' '; i++);

            if(i >= n)
            {
                break;
            }

            int j = i;
            for(; j < n && s[j] != ' '; j++);

            word = s.substr(i, j - i);

            if(result == "")
            {
                result = word;
            }
            else
            {
                result = word + " " + result;  // This reverses the words
            }

            i = j;
        }

        return result;
    }
};

// Better solutions

// class Solution {
// public:
//     string reverseWords(string s) {
//         reverse(s.begin(), s.end());
//         int n = s.size();
//         int left = 0;
//         int right = 0;
//         int i = 0;
//         while (i < n) {
//             while (i < n && s[i] == ' ')
//                 i++;
//             if (i == n)
//                 break;
//             while (i < n && s[i] != ' ') {
//                 s[right++] = s[i++];
//             }
//             reverse(s.begin() + left, s.begin() + right);
//             s[right++] = ' ';
//             left = right;
//             i++;
//         }
//         s.resize(right - 1);
//         return s;
        
//     }
// };


// class Solution {
// public:
//     string reverseWords(string s) {
//         int n = s.length();
//         int i = 0;
//         deque<string> words;

//         while (i < n) {
//             // Skip spaces
//             while (i < n && s[i] == ' ') {
//                 i++;
//             }

//             // Find the next word
//             int j = i;
//             while (j < n && s[j] != ' ') {
//                 j++;
//             }

//             // If we found a word, add it to the front of the deque
//             if (i < n) {
//                 words.push_front(s.substr(i, j - i));
//             }

//             i = j;
//         }

//         // Join words with a single space
//         string result = "";
//         while (!words.empty()) {
//             result += words.front();
//             words.pop_front();
//             if (!words.empty()) {
//                 result += " ";
//             }
//         }

//         return result;
//     }
// };