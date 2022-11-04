class Solution {
private:
    bool isVowel(char c) const {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    string reverseVowels(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !isVowel(s[left]))
                left++;
            while (left < right && !isVowel(s[right]))
                right--;
            if (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};
