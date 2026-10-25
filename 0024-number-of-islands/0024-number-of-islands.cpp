class Solution {
public:

    void bfs(vector<vector<int>>& vist,
             vector<vector<char>>& grid,
             int row, int col) {

        queue<pair<int, int>> q;

        q.push({row, col});
        vist[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

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
                    grid[nrow][ncol] == '1' &&
                    !vist[nrow][ncol]) {

                    vist[nrow][ncol] = 1;

                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        vector<vector<int>> vist(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {

            for (int col = 0; col < m; col++) {

                if (!vist[row][col] && grid[row][col] == '1') {

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