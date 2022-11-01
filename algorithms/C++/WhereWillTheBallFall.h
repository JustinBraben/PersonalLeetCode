class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<int> res(n, 0);

        for (int i = 0; i < n; i++) {
            int curRow = 0;
            int curCol = i;

            while (1) {
                // Can leverage the value of the slant to move left or right based on it
                // -1 will look left, +1 will look right
                int newCol = grid[curRow][curCol] + curCol;

                // if it does not get blocked move to the next row
                if (newCol >= 0 && newCol < n && grid[curRow][curCol] == grid[curRow][newCol]) {
                    curRow++;
                    curCol = newCol;
                }
                else {
                    // ran into a V block, break
                    res[i] = -1;
                    break;
                }

                if (curRow >= m) {
                    // we it fell all the way down to the last row
                    res[i] = curCol;
                    break;
                }
            }
        }

        return res;
    }
};