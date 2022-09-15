class RecurseSolution {
public:
    vector<int> memoRob;
    int recurseRob(vector<int>& nums, int numsIndex) {
        if (numsIndex < 0)
            return 0;
        return std::max(recurseRob(nums, numsIndex - 2) + nums[numsIndex], recurseRob(nums, numsIndex - 1));
    }

    int rob(vector<int>& nums) {
        return recurseRob(nums, nums.size() - 1);
    }
};

class RecurseMemoTopDownSolution {
public:
    vector<int> memoRob;
    int recurseRob(vector<int>& nums, int numsIndex) {
        if (numsIndex < 0)
            return 0;
        if (memoRob[numsIndex] >= 0)
            return memoRob[numsIndex];
        return memoRob[numsIndex] = max(recurseRob(nums, numsIndex - 2) + nums[numsIndex], recurseRob(nums, numsIndex - 1));
    }

    int rob(vector<int>& nums) {
        memoRob.resize(nums.size() + 1, -1);
        return recurseRob(nums, nums.size() - 1);
    }
};

class IterativeMemoBottomUpSolution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        vector<int> memoRob(n + 1, 0);
        memoRob[0] = 0;
        memoRob[1] = nums[0];

        for (int i = 1; i < n; i++)
            memoRob[i + 1] = max(memoRob[i], memoRob[i - 1] + nums[i]);

        return memoRob[n];
    }
};