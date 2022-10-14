class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {

        int n = nums.size(), res = 0, j = 0;
        sort(begin(nums), end(nums));
        for (int i = 0; i < n; ) {

            int cur = nums[i], count = 0;

            // array is sorted so if we run into duplicates keep a count of the duplicates
            // then we only perform the rest of the while loops not on duplicate values
            while (i < n && nums[i] == cur) {
                ++i;
                ++count;
            }

            while (j < n && nums[j] < cur + k)
                ++j;

            int start = j;

            while (j < n && nums[j] == cur + k)
                ++j;

            res += (j - start) * count;
        }
        return res;
    }
};