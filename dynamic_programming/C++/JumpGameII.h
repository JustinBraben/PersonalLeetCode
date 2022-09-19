class RecurseSolution {
public:

    long long int jumpRecurse(vector<int> nums, int currIndex, int dest) {
        if (currIndex >= dest) return 0;
        long long int tmp = INT_MAX;

        //Try Every jump 1 to nums[curr] jump
        //and find minimum steps need to reach to end

        for (int i = 1; i <= nums[currIndex]; i++) {
            tmp = min(tmp, 1 + jumpRecurse(nums, currIndex + i, dest));
        }
        return tmp;
    }

    int jump(vector<int>& nums) {
        return jumpRecurse(nums, 0, nums.size() - 1);
    }
};

class MemoRecurseSolution {
public:

    long long int jumpDP(vector<int>& nums, int currIndex, int dest, vector<int>& dp) {
        if (currIndex == dest) return 0;
        if (dp[currIndex] != -1) return dp[currIndex];

        long long int tmp = INT_MAX;

        for (int i = 1; i <= nums[currIndex]; i++) {
            if (i + currIndex > dest) break;
            tmp = min(tmp, 1 + jumpDP(nums, currIndex + i, dest, dp));
        }
        return dp[currIndex] = tmp;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return jumpDP(nums, 0, nums.size() - 1, dp);
    }
};