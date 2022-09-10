class Solution {
public:
    static bool compareCharacter(const std::vector<int>& chara1, const std::vector<int>& chara2) {
        // Within groups of same attack sort by defense descending
        if (chara1[0] == chara2[0])
            return (chara1[1] > chara2[1]);
        // Sort by attack ascending
        return chara1[0] < chara2[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        sort(properties.begin(), properties.end(), compareCharacter);
        int mtn = INT_MIN;              // max till now moving from right to left of array
        int res = 0;

        for (int i = properties.size() - 1; i >= 0; i--) {
            if (properties[i][1] < mtn) // if the second parameter is also less increase the ans
                res++;
            mtn = max(mtn, properties[i][1]);
        }

        return res;
    }
};