class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX, sum1 = 0, sum2 = 0, totalSum = 0;

        for (auto num : nums) {
            totalSum += num;
            sum1 += num;
            sum2 += num;

            maxSum = max(maxSum, sum1);

            if (sum1 < 0) sum1 = 0; // reset sum to 0 if it is negative

            minSum = min(sum2, minSum);

            if (sum2 > 0) sum2 = 0; // reset sum to 0 if it is negative
        }
        if (totalSum == minSum) return maxSum;
        return max(maxSum, totalSum - minSum);
    }
};