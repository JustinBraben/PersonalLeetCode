class Solution {
public:
    string longestPalindrome(string s) {
        string longestSubString = s.substr(0, 1);
        int left = 0, right = 0;

        for (int i = 0; i < s.length(); ++i) {

            int l = i, r = i;

            // odd length cases
            while (l >= 0 && r < s.length() && s[l] == s[r]) {

                if ((r - l + 1) > longestSubString.length()) {
                    longestSubString = s.substr(l, r - l + 1);
                }

                l -= 1;
                r += 1;
            }

            // even cases
            l = i, r = i + 1;
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if ((r - l + 1) > longestSubString.length()) {
                    longestSubString = s.substr(l, r - l + 1);
                }

                l -= 1;
                r += 1;
            }
        }
        return longestSubString;
    }
};