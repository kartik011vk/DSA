class Solution {
public:

    void bfs(vector<vector<int>>& vist,
             vector<vector<int>>& grid,
             int row, int col) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        q.push({row, col});
        vist[row][col] = 1;

        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {

                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 0 &&
                    !vist[nrow][ncol]) {

                    vist[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vist(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {

            if (grid[row][0] == 0 && !vist[row][0]) {
                bfs(vist, grid, row, 0);
            }

            if (grid[row][m - 1] == 0 && !vist[row][m - 1]) {
                bfs(vist, grid, row, m - 1);
            }
        }

        for (int col = 0; col < m; col++) {

            if (grid[0][col] == 0 && !vist[0][col]) {
                bfs(vist, grid, 0, col);
            }

            if (grid[n - 1][col] == 0 && !vist[n - 1][col]) {
                bfs(vist, grid, n - 1, col);
            }
        }

        int cnt = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (grid[row][col] == 0 && !vist[row][col]) {

                    cnt++;

                    bfs(vist, grid, row, col);
                }
            }
        }

        return cnt;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna