class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {

        // The path taken has lead to an obstacle.
        // Immediately exit this path
        if (row >= 0 && col >= 0 && obstacleGrid[row][col] == 1)
            return 0;

        // You have reached the initial spot!
        // this is a useable path
        if (row == 0 && col == 0)
            return 1;

        // Out of bounds, exit
        if (row < 0 || col < 0)
            return 0;

        // All spots of the dp are initialized at -1
        // If the spot has been updated since initialized
        // return it
        if (dp[row][col] != -1)
            return dp[row][col];

        // Call recursively, travelling from the endpoint to the beginning
        // Will attempt to go up and left from the end
        // and will exit when on improper path
        // or return 1 if it makes it to the entrance
        int up = dfs(row - 1, col, obstacleGrid, dp);
        int left = dfs(row, col - 1, obstacleGrid, dp);

        dp[row][col] = up + left;

        // The final spot of the dp with contain the number of unique paths
        return dp[row][col];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(m - 1, n - 1, obstacleGrid, dp);
    }
};