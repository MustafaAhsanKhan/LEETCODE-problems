#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words)
    {
        vector<string> result;
        set<char> set1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        set<char> set2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        set<char> set3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        
        for (const string& word : words)
        {
            set<char> w;
            for (char ch : word)
            {
                w.insert(tolower(ch));
            }
            if (includes(set1.begin(), set1.end(), w.begin(), w.end()) ||
                includes(set2.begin(), set2.end(), w.begin(), w.end()) ||
                includes(set3.begin(), set3.end(), w.begin(), w.end()))
            {
                result.push_back(word);
            }
        }
        
        return result;
    }
};