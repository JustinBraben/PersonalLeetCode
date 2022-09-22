class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxVal = values[0];
        int res = INT_MIN;

        for (int i = 1; i < values.size(); i++) {
            maxVal = max(maxVal, values[i - 1] + i - 1);
            res = max(res, maxVal + values[i] - i);
        }

        return res;
    }
};