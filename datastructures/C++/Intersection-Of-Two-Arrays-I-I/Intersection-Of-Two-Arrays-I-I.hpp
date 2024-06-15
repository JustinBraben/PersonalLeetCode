class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> result;

        // Map with key as a number, value as the frequency its found in the array
        // Hence the ++ to increase value
        for (auto i : nums1)
            umap[i]++;

        // If there is a key of umap[j]
        // check to see if its not 0
        // if it is 0 then its not available to be used 
        // in the resulting overlap array
        for (auto j : nums2) {
            if (umap[j]-- > 0)
                result.push_back(j);
        }

        return result;
    }
};