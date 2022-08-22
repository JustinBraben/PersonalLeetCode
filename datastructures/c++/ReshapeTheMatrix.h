class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();
        int total = rows * cols;

        // Return the original array if the transformation is not possible
        // based off total entries
        if (r * c != total)
            return mat;

        // Initialize new vector with size of r and c
        vector<vector<int>> result(r, vector<int>(c));

        // 2d array transform
        for (int i = 0; i < total; i++)
            result[i / c][i % c] = mat[i / cols][i % cols];

        return result;
    }
};