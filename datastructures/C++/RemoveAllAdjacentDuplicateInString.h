class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";

        for (char& c : s) {
            // check if size of result is not 0
            // if the current character is the same as the last character in the res string don't add it
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);   // if the last character is not the same as the character to be added, add it to the result string
        }

        return res;
    }
};