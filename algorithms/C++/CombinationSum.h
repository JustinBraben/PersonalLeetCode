class Solution {
private:
    vector<vector<int>> res;    // 2D vector with our answer
public:

    void solve(int i, vector<int>& candidates, vector<int>& tmp, int target) {
        if (target == 0) {
            res.push_back(tmp); // means we have found an answer
            return;             // exit
        }

        if (target < 0)         // out of target bounds
            return;             // exit

        if (i == candidates.size()) // out of target bounds
            return;                 // exit

        // we have not taken the ith element,
        // so without decreasing sum we will move to next index because it will not contribute in making our sum
        solve(i + 1, candidates, tmp, target);

        tmp.push_back(candidates[i]);   // now added ith element

        solve(i, candidates, tmp, target - candidates[i]);  // thus decrease the sum and call again

        tmp.pop_back(); // remove the most recent element to backtrack
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();

        vector<int> tmp;

        solve(0, candidates, tmp, target);

        return res;
    }
};