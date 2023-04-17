class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandie = 0;
        vector<bool> res;

        for (auto candie : candies) {
            maxCandie = max(maxCandie, candie);
        }

        for (auto candie : candies) {
            if (candie + extraCandies >= maxCandie) {
                res.push_back(true);
            }
            else {
                res.push_back(false);
            }
        }

        return res;
    }
};