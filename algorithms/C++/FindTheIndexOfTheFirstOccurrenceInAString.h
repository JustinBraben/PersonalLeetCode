class Solution {
public:
    int strStr(string haystack, string needle) {
        std::size_t found = haystack.find(needle);
        if (found != std::string::npos)
            return found;
        return -1;
    }
};