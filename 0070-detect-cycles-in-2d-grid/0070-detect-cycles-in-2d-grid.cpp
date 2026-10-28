class Solution {
public:

    bool dfs(vector<vector<char>>& grid, vector<vector<int>>& vis,
             int sr, int sc, int parent_row, int parent_col,
             char ch, int del_row[], int del_col[]) {

        int n = grid.size();
        int m = grid[0].size();

        vis[sr][sc] = 1;

        for (int i = 0; i < 4; i++) {

            int n_row = sr + del_row[i];
            int n_col = sc + del_col[i];

            if (n_row >= 0 && n_row < n &&
                n_col >= 0 && n_col < m &&
                grid[n_row][n_col] == ch) {

                if (vis[n_row][n_col] == 0) {

                    if (dfs(grid, vis, n_row, n_col,
                            sr, sc, ch, del_row, del_col)) {
                        return true;
                    }

                }
                else if (n_row != parent_row || n_col != parent_col) {
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int del_row[4] = {-1, 0, 1, 0};
        int del_col[4] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (vis[i][j] == 0) {

                    if (dfs(grid, vis, i, j, -1, -1,
                            grid[i][j], del_row, del_col)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna