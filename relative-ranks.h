#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        int size = score.size();
        vector<pair<int,int>> v(size);

        for(int i = 0; i < size; ++i)
        {
            v[i].first = score[i];
            v[i].second = i;
        }

        sort(v.rbegin(), v.rend());

        vector<string> ans(size);

        if(size >= 1) ans[v[0].second] = "Gold Medal";
        if(size >= 2) ans[v[1].second] = "Silver Medal";
        if(size >= 3) ans[v[2].second] = "Bronze Medal";

        for(int i = 3; i < size; ++i)
        {
            ans[v[i].second] = to_string(i + 1);
        }

        return ans;
    }
};