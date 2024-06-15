class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> rNote;
        unordered_map<char, int> mZine;
        bool possible = true;

        for (auto c : ransomNote)
            rNote[c]++;

        for (auto c : magazine)
            mZine[c]++;

        for (int i = 0; i < ransomNote.size(); ++i) {
            if (rNote[ransomNote[i]] > mZine[ransomNote[i]])
                possible = false;
        }

        return possible;
    }
};