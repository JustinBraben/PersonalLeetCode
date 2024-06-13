class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Keeps track of all subsets in a vector
        // initial vector with [] empty value
        std::vector<std::vector<int>> res = { {} };

        // Iterate over each number in the input vector
        for (const auto& num : nums) {
            // Get the current size of the result vector (number of subsets so far)
            int n = res.size();

            // Iterate over all existing subsets
            for (int i = 0; i < n; ++i) {
                // Create a new subset by copying an existing subset
                std::vector<int> subset = res[i];
                // Add the current number to this new subset
                subset.push_back(num);
                // Add the new subset to the result vector
                res.push_back(subset);
            }
        }

        return res;
    }
};