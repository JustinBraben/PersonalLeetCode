class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() < 1) return 0;

        int left = 0;

        for (int right = 1; right < nums.size(); ++right) {

            if (nums[left] != nums[right]) {
                left++;
                nums[left] = nums[right];
            }

        }

        return left + 1;
    }
};