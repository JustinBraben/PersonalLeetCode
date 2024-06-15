class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //Key is the number and value is its index in the vector.
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(target - nums[i]) != umap.end()) {
                return { umap[target - nums[i]], i };
            }
            umap[nums[i]] = i;
        }

        return {};
    }
};