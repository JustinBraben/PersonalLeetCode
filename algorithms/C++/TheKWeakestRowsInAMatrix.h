class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {

        vector<pair<int, int>> strength;    // Pair of (number of soldiers, row index)

        // Count soldiers in each row and store in the vector
        for (int i = 0; i < mat.size(); ++i) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); ++j) {
                if (mat[i][j] == 1) {
                    count++;
                }
                else {
                    break; // As all 1's appear to the left of 0's
                }
            }
            strength.push_back({ count, i });
        }

        // Sort based on the number of soldiers and row index
        sort(strength.begin(), strength.end(), [](const pair<int, int>& a, const pair<int, int>& b) {

            // If the number of soldiers are the same
            // the weaker row will be the lower row number
            if (a.first == b.first) {
                return a.second < b.second;
            }

            // otherwise the weaker row is determined by whichever one has less soldiers
            return a.first < b.first;
            });

        vector<int> res;    // result vector should have the weakest k number of rows
        // from weakest to strongest

        for (int i = 0; i < k; ++i) {
            res.push_back(strength[i].second);
        }

        return res;
    }
};