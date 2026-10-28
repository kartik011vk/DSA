class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int sr, int sc,
                  int del_row[], int del_col[]) {

        int row = grid.size();
        int col = grid[0].size();

        long long sum = grid[sr][sc];
        grid[sr][sc] = 0;

        for (int d = 0; d < 4; d++) {
            int n_row = sr + del_row[d];
            int n_col = sc + del_col[d];

            if (n_row >= 0 && n_row < row &&
                n_col >= 0 && n_col < col &&
                grid[n_row][n_col] > 0) {

                sum += dfs(grid, n_row, n_col, del_row, del_col);
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        int del_row[4] = {-1, 0, 1, 0};
        int del_col[4] = {0, 1, 0, -1};

        int count = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 0) {
                    continue;
                }

                long long sum = dfs(grid, i, j, del_row, del_col);

                if (sum % k == 0) {
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