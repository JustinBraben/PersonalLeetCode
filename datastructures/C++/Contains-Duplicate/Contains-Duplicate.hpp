class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;

        for (auto x : nums) {

            if (mp[x])
                return true;

            mp[x] = true;
        }

        return false;
    }
};