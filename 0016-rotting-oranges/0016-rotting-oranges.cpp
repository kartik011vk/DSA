class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cntfresh = 0 ;
        int n  = grid.size() ;
        int m  = grid[0].size() ; 
        int vis[n][m] ; 
        queue<pair<pair<int, int>, int>> q ; 
        for (int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2 ){
                    q.push({{i, j}, 0}) ; 
                    vis[i][j] = 2 ; 
                }
                else{
                    vis[i][j] = 0 ; 
                }
                if(grid[i][j] == 1){
                    cntfresh++ ; 
                }
            }
        }

        int tm = 0 ; 
        int del_r[] = {-1, 0, 1, 0} ;
        int del_c[] = {0, 1, 0, -1} ; 
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first ; 
            int c = q.front().first.second ; 
            int t = q.front().second ;
            tm = max(tm , t) ;
            q.pop() ;
            for(int i = 0 ; i< 4 ; i++){
                int new_r = r + del_r[i] ; 
                int new_c = c + del_c[i] ; 
                if(new_r >=0 && new_r < n && new_c >=0 && new_c < m && vis[new_r][new_c] == 0 && grid[new_r][new_c] == 1 ){
                    q.push({{new_r, new_c}, t+1}) ;
                    vis[new_r][new_c] = 1; 
                    cnt++ ; 
                }
            }

        }
        if(cntfresh != cnt){
            return -1 ; 
        }
        return tm ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna