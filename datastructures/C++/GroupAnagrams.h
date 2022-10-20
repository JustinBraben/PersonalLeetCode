class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> res;

        // store all strings in temp string
        // sort the temp strings and add them to a map, with the key being the original
        // value being the sorted value
        for (const auto& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            umap[temp].push_back(s);
        }

        res.reserve(umap.size());
        for (auto& entry : umap)
            res.push_back(std::move(entry.second));

        return res;
    }
};