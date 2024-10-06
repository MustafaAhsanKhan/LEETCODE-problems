class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        set<int> seen;  // Set to store unique elements

        for (int num : nums)
        {
            // If num is already in the set, it means we found a duplicate
            if (seen.find(num) != seen.end())
            {
                return true;
            }
            // Otherwise, insert the number into the set
            seen.insert(num);
        }

        // If no duplicates were found, return false
        return false;
    }
};