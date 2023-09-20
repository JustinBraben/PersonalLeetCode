class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> prefix = { nums[0] }; // Initialize a prefix sum array with the first element of nums.

        for (int i = 1; i < n; i++) {
            // Calculate the prefix sum for each element in nums.
            if (prefix[i - 1] >= x) break; // If the sum exceeds x, exit the loop.
            prefix.push_back(prefix[i - 1] + nums[i]);
        }

        int sz = prefix.size(); // Get the size of the prefix sum array.

        int idx = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin(); // Find the index of x in the prefix sum array.

        int ans = INT_MAX; // Initialize ans to a large value.

        if (idx != sz && prefix[idx] == x) {
            ans = idx + 1; // If x is found in the prefix sum array, update ans.
        }

        for (int j = n - 1; j >= 0; j--) {
            x -= nums[j]; // Subtract the current element from x.

            if (x < 0) break; // If x becomes negative, exit the loop.

            if (x == 0) ans = min(ans, (n - j)); // If x becomes zero, update ans with the length of the subarray.

            idx = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin(); // Find the index of x in the prefix sum array.

            if (idx < j && prefix[idx] == x) {
                // If x is found before the current element in the prefix sum array, update ans.
                ans = min(ans, idx + 1 + (n - j));
            }
        }

        return ans == INT_MAX ? -1 : ans; // If ans is still the initial large value, return -1; otherwise, return ans.
    }
};