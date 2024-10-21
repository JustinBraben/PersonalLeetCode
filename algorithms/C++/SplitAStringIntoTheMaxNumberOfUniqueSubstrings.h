class Solution {
private:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        // Base case: if we've reached the end of the string
        if (start >= s.length()) {
            return 0;
        }

        int maxSplits = 0;

        // Try all possible substrings starting from 'start'
        for (int i = start; i < s.length(); i++) {
            string substr = s.substr(start, i - start + 1);

            // If this substring hasn't been used before
            if (seen.find(substr) == seen.end()) {
                seen.insert(substr);

                // Recursively process the rest of the string
                int splits = 1 + backtrack(s, i + 1, seen);
                maxSplits = max(maxSplits, splits);

                // Backtrack by removing the substring
                seen.erase(substr);
            }
        }

        return maxSplits;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;

        auto s_size = s.size();
        cout << "s_size: " << s_size << "\n";
        cout << "front: " << s.front() << "\n";
        cout << "back: " << s.back() << "\n";

        return backtrack(s, 0, seen);
    }
};