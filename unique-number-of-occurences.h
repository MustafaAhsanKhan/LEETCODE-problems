#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>


class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
    // Step 1: Create a frequency map
    std::unordered_map<int, int> frequencyMap;
    for (int num : arr) {
        frequencyMap[num]++;
    }
    
    // Step 2: Create a set to store unique occurrence counts
    std::unordered_set<int> occurrenceSet;
    for (const auto& pair : frequencyMap) {
        // Try to insert the occurrence count into the set
        if (!occurrenceSet.insert(pair.second).second) {
            // If insertion fails, occurrence count is not unique
            return false;
        }
    }
    
    // If all occurrence counts are unique, return true
    return true;
}
};