class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int res = 0;
        int maxFreq = INT_MIN;
        unordered_map<int, vector<int>> umap;

        for (int i = 0; i < nums.size(); i++)
            umap[nums[i]].push_back(i);

        for (auto& entry : umap) {
            int frequency = entry.second.size();
            int len = entry.second.back() - entry.second.front() + 1;
            if (frequency > maxFreq) {
                maxFreq = frequency;
                res = len;
            }
            else if (frequency == maxFreq)
                res = min(res, len);
        }

        return res;
    }
};