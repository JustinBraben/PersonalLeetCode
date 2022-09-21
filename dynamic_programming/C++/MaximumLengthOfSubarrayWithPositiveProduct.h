class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        long long int i, n = nums.size(), res = 0;

        // Vector for positive numbers and negative numbers
        vector<long long int> pos(n), neg(n);

        pos[0] = nums[0] > 0 ? 1 : 0;
        neg[0] = nums[0] < 0 ? 1 : 0;
        res = pos[0];

        for (i = 1; i < n; i++) {
            if (nums[i] > 0) {
                pos[i] = 1 + pos[i - 1];
                neg[i] = neg[i - 1] > 0 ? 1 + neg[i - 1] : 0;
            }
            else if (nums[i] < 0) {
                pos[i] = neg[i - 1] > 0 ? 1 + neg[i - 1] : 0;
                neg[i] = 1 + pos[i - 1];;
            }
            res = max(res, pos[i]);
        }

        return res;
    }
};