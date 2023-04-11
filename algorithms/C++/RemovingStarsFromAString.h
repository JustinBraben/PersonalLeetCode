class Solution {
public:
    string removeStars(string s) {
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];

            if (currentChar == '*' && res.length() > 0)
                res.pop_back();
            else
                res += currentChar;
        }

        return res;
    }
};