#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty()) return 0;

        int substr_index = 0;
        for (int i = 0; i < haystack.size();)
        {
            if (needle[substr_index] == haystack[i])
            {
                substr_index++;
                i++;

                // If we've reached the end of the needle, return the starting index
                if (substr_index == needle.size())
                {
                    return i - substr_index;
                }
            }
            else
            {
                // Reset substr_index to 0 and move i back to the next position after the failed attempt
                i = i - substr_index + 1;
                substr_index = 0;
            }
        }

        return -1;
    }
};

// An Alternate solution

// class Solution {
// public:
//     int strStr(string haystack, string needle)
//     {
//         if (needle.empty())  // If needle is an empty string, return 0
//         {
//             return 0;
//         }

//         int haystack_len = haystack.size();
//         int needle_len = needle.size();

//         for (int i = 0; i <= haystack_len - needle_len; ++i)
//         {
//             int j = 0;
//             // Check if needle matches starting from position i in haystack
//             while (j < needle_len && haystack[i + j] == needle[j])
//             {
//                 j++;
//             }
//             if (j == needle_len)  // If we've matched the entire needle
//             {
//                 return i;
//             }
//         }

//         return -1;  // No match found
//     }
// };