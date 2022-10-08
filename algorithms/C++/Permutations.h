class Solution {
public:

    void solve(vector<int> nums, int i, vector<vector<int>>& perms) {
        if (i == nums.size()) {
            perms.push_back(nums);
        }
        else {
            for (int j = i; j < nums.size(); j++) {
                swap(nums[i], nums[j]);
                solve(nums, i + 1, perms);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        solve(nums, 0, perms);
        return perms;
    }
};