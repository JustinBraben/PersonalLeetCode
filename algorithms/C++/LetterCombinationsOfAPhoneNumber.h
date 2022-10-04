class Solution {
public:
    const vector<string> pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        res.push_back("");

        for (auto digit : digits) {

            vector<string> tmp;

            for (auto candidate : pad[digit - '0']) {    // digit - '0' will give you the index of pad
                                                        // with the string values we want
                for (auto s : res) {
                    tmp.push_back(s + candidate);       // will loop through the current result
                                                        // and adds the next loop of characters corresponding to the pad
                }
            }

            res.swap(tmp);                              // Swap to the tmp vector with our updated entries
        }

        return res;
    }
};