class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int p1 = 0, p2 = n - 1;
        while (p1 < p2) {
            for (int i = 0; i < (p2 - p1); ++i) {
                swap(matrix[p1][p1 + i], matrix[p1 + i][p2]);
                swap(matrix[p1][p1 + i], matrix[p2][p2 - i]);
                swap(matrix[p1][p1 + i], matrix[p2 - i][p1]);
            }
            ++p1;
            --p2;
        }
    }
};