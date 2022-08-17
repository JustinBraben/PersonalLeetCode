class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;

        for (auto& x : nums) {
            sum = max(sum + x, x);
            res = max(res, sum);
        }

        return res;
    }
};