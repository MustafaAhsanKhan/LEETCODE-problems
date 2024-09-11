#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.empty()) return "";
        string prefix = "";
        
        for(int index = 0; index < strs[0].size(); ++index)
        {
            char ch = strs[0][index];
            for(int j = 1; j < strs.size(); ++j)
            {
                if(index >= strs[j].size() || strs[j][index] != ch)
                {
                    return prefix;
                }
            }
            prefix += ch;
        }

        return prefix;
    }
};
