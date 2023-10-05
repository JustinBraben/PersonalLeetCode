class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> numsFreq;
        int n = nums.size();

        for (const auto& num : nums) {
            numsFreq[num]++;
        }

        int x = n / 3;

        for (auto& entry : numsFreq) {
            if (entry.second > x)
                res.push_back(entry.first);
        }

        return res;
    }
};