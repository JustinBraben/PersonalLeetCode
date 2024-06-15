class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        unordered_map<char, int> sMap, tMap;

        for (auto c : s)
            sMap[c]++;

        for (auto c : t)
            tMap[c]++;

        for (int i = 0; i < s.size(); ++i) {
            if (sMap[s[i]] != tMap[s[i]])
                return false;
        }

        return true;
    }
};