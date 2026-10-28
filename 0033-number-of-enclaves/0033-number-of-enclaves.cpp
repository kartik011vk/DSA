class Solution {
public:
    void dfs(vector<vector<int>>& grid, int sr, int sc,
             int del_row[], int del_col[]) {

        int row = grid.size();
        int col = grid[0].size();

        grid[sr][sc] = 0;

        for (int i = 0; i < 4; i++) {
            int n_row = sr + del_row[i];
            int n_col = sc + del_col[i];

            if (n_row >= 0 && n_row < row &&
                n_col >= 0 && n_col < col &&
                grid[n_row][n_col] == 1) {

                dfs(grid, n_row, n_col, del_row, del_col);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int del_row[4] = {-1, 0, 1, 0};
        int del_col[4] = {0, 1, 0, -1};

        for (int i = 0; i < row; i++) {
            if (grid[i][0] == 1) {
                dfs(grid, i, 0, del_row, del_col);
            }

            if (grid[i][col - 1] == 1) {
                dfs(grid, i, col - 1, del_row, del_col);
            }
        }

        for (int j = 0; j < col; j++) {
            if (grid[0][j] == 1) {
                dfs(grid, 0, j, del_row, del_col);
            }

            if (grid[row - 1][j] == 1) {
                dfs(grid, row - 1, j, del_row, del_col);
            }
        }
// Count the remaining land cells.
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna