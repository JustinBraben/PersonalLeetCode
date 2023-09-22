class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = s.size();
        int j = t.size();
        int first = 0;
        int second = 0;

        // Keep iterating through the second string until it reaches the end
        // Move along the first string index if it finds the same character 
        // in string s and string t
        while (second < j) {
            if (s[first] == t[second]) {
                first++;
                second++;
            }
            else
                second++;
        }

        if (first == i)
            return true;
        else
            return false;
    }
};