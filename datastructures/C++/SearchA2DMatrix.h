class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int val = matrix[mid / col][mid % col];
            if (target < val)
                right = mid - 1;
            else if (target > val)
                left = mid + 1;
            else
                return true;
        }

        return false;
    }
};