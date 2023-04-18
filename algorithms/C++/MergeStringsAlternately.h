class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int count = 0;

        while (count < word1.length() || count < word2.length()) {
            if (count < word1.length())
                res += word1[count];
            if (count < word2.length())
                res += word2[count];
            count++;
        }

        return res;
    }
};