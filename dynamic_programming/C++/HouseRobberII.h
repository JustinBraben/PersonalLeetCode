class Solution {
public:
    int robOriginal(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> memoRob(n);
        memoRob[0] = nums[0];
        memoRob[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
            memoRob[i] = max(memoRob[i - 1], memoRob[i - 2] + nums[i]);

        return memoRob[n - 1];
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        vector<int> numsA(nums.begin(), nums.end() - 1);
        vector<int> numsB(nums.begin() + 1, nums.end());

        return max(robOriginal(numsA), robOriginal(numsB));
    }
};