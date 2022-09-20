class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Return early if input is empty
        if (nums.empty()) return 0;

        int bestProduct = INT_MIN;

        // Running Products
        int minProduct = 1;
        int maxProduct = 1;

        for (int num : nums) {
            if (num < 0) {
                // Swap max and min
                swap(maxProduct, minProduct);
            }
            // Reset to current value if smaller or larger than it
            // (intuitively means that we start considering a new sub-array)
            maxProduct = max(maxProduct * num, num);
            minProduct = min(minProduct * num, num);

            // Update the best
            bestProduct = max(bestProduct, maxProduct);
        }

        return bestProduct;
    }
};