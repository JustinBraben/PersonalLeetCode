#include "001-Two-Sum.hpp"

static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	std::cin.tie(NULL);
	return 0;
}();

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {
    
    //Key is the number and value is its index in the vector.
    std::unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); i++) {
        if (umap.find(target - nums[i]) != umap.end()) {
            return { umap[target - nums[i]], i };
        }
        umap[nums[i]] = i;
    }

    return {};
}
