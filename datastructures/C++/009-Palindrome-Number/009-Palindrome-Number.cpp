#include "009-Palindrome-Number.hpp"

static auto x = []() {
	// turn off sync
	std::ios::sync_with_stdio(false);
	// untie in/out streams
	std::cin.tie(NULL);
	return 0;
}();

int Solution::Reverse(int x) {
    
    int result  = 0;
    bool negative = false;
    
    if(x < 0){
        negative = true;
        x = -x;
    }
    
    while(x != 0){
        int currentDigit = x % 10;
        result = result * 10 + currentDigit;
        x /= 10;
    }
    
    return result;
}

bool Solution::IsPalindrome(int x) {
    if (x < 0)
        return false;
    
    return ((Reverse(x) == x));
}
