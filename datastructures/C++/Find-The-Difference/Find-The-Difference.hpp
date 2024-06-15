class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> charCount;

        // Count the occurrences of characters in string s
        for (char c : s) {
            charCount[c]++;
        }

        // Iterate through string t and find the extra character
        for (char c : t) {
            if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
                return c;
            }
            else {
                charCount[c]--;
            }
        }

        // In case there is no extra character, you can return a default value or handle it accordingly.
        return '\0';
    }
};