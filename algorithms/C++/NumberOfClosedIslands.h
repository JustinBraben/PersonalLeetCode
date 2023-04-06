class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        // Make sure we don't traverse out of bounds
        // Make sure the current grid spot is not 0 (make sure it is land)
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 0)
            return;

        grid[i][j] = 1;

        // Using these array values to find out what values are in positions
        // to the right, to the left, on top, and below the current array spot you are looking at
        int dx[4] = { 1, -1, 0, 0 };
        int dy[4] = { 0, 0, 1, -1 };

        for (int k = 0; k < 4; k++) {
            int newX = i + dx[k];
            int newY = j + dy[k];
            dfs(newX, newY, grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Look at every spot in the array 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // If the spot is 0 and not around the edges of the array
                // run the dfs
                if ((i * j == 0 || i == m - 1 || j == n - 1) && (grid[i][j] == 0))
                    dfs(i, j, grid);
            }
        }

        // Now count the number of closed islands
        int count = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0) {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};