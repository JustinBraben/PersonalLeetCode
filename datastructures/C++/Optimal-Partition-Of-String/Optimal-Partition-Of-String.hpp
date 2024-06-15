class Solution {
public:
    int partitionString(string s) {
        int partitions = 1;
        unordered_set<char> seen;

        // Iterate the entire string and increase partitions
        for (auto letter : s) { // O(n)

            // If the letter is part of the current partition
            // We reset the hashset
            if (seen.find(letter) != seen.end()) {
                seen.clear(); // O(26)
                partitions++;
            }

            // Add letter to hashset
            seen.insert(letter);
        }

        return partitions;
    }
};