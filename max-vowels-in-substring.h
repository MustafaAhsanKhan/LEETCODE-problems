#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k)
    {
        if(s.size() < k)
        {
            return 0;
        }

        int max_vowels = 0;
        int vowels = 0;

        // first window
        for(int i = 0; i < k; ++i)
        {
            if(isVowel(s[i]))
            {
                vowels++;
            }
        }

        max_vowels = vowels;

        for(int i = k; i < s.size(); ++i)
        {
            if(isVowel(s[i]))
            {
                vowels++;
            }
            if(isVowel(s[i - k]))
            {
                vowels--;
            }
            max_vowels = max(max_vowels, vowels);
        }

        return max_vowels;
    }

private:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};

// #include "max-vowels-in-substring.h"

// int main()
// {
//     Solution foo;

//     cout << foo.maxVowels("iiiabc", 3);
// }