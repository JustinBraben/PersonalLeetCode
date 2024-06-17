#include <gtest/gtest.h>
#include "009-Palindrome-Number.hpp"

TEST(PalindromeNumberTest, CASE_1) {
    int tc_1 = 121;
    int tc_2 = -121;
    int tc_3 = 10;

    Solution s;
    auto res_1 = s.IsPalindrome(tc_1);
    auto res_2 = s.IsPalindrome(tc_2);
    auto res_3 = s.IsPalindrome(tc_3);

    EXPECT_EQ(res_1, true);
    EXPECT_EQ(res_2, false);
    EXPECT_EQ(res_3, false);
}