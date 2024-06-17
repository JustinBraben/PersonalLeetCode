#include <gtest/gtest.h>
#include "001-Two-Sum.hpp"

TEST(TwoSumTest, CASE_1) {
    std::vector<int> nums = {2,7,11,15};
    int target = 9;
    std::vector<int> expected = {0,1};

    Solution s;
    auto res = s.twoSum(nums, target);

    EXPECT_EQ(res, expected);
}