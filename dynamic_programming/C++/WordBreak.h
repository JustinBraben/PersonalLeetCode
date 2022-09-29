class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        set<string> dict;
        for (auto w : wordDict)
            dict.insert(w);

        vector<bool> dp(n + 1, false);
        dp[0] = true; // Make an empty string with any wordDict

        //From every i position check if you can make word ending here
        for (int i = 0; i < n; i++) {

            //If we can make a word from j->i
            //We need to check if we can make a word till j first
            for (int j = i; j >= 0; j--) {
                string currWord = s.substr(j, i - j + 1);    //pos, noOfChars

                if (dict.find(currWord) != dict.end())
                    dp[i + 1] = dp[i + 1] || dp[j];             //dp[j] have we used these words before?  (j(dp is 1 indexed))

                if (dp[i + 1])
                    break;
            }
        }

        return dp[n];
    }
};