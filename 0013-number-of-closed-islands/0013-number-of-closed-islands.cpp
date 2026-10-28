class Solution {
public:

    void dfs(vector<vector<int>>& grid,vector<vector<int>> &vist, int sr, int sc, int del_row[], int del_col[] ){
        int row = grid.size() ;
        int col = grid[0].size() ; 
        vist[sr][sc] = 1 ;
        int n_row ; 
        int n_col ; 
        for(int i = 0 ; i< 4 ; i++){
            n_row = del_row[i] + sr ; 
            n_col = del_col[i] + sc ;
        if (n_row >= 0 && n_row < row && n_col >= 0 && n_col < col && grid[n_row][n_col] == 0  && vist[n_row][n_col] != 1) {
            dfs(grid, vist, n_row, n_col, del_row, del_col) ; 
        } 
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        int m = grid[0].size() ; 
        vector<vector<int>> vist = grid ; 
        int cnt = 0 ; 
        int del_row[] = {-1, 0, 1, 0} ; 
        int del_col[] = {0, 1, 0, -1} ; 
        for(int i = 0 ; i< n ; i++){
            if(vist[i][0] == 0 ){
                dfs(grid ,vist, i , 0, del_row, del_col ) ;
            }
            if(vist[i][m -1 ] == 0){
                dfs(grid ,vist, i , m -1 , del_row, del_col ) ;                
            }
        }
        for(int j =0 ; j < m ; j++){
            if(vist[0][j] == 0){
                dfs(grid, vist, 0, j, del_row, del_col) ; 
            }
            if(vist[n-1][j] == 0){
                dfs(grid, vist,n-1 , j, del_row, del_col) ; 
            }
        }

        for(int i = 0 ; i < n; i++ ){
            for(int j =0 ; j <  m ; j++){
                if(vist[i][j] == 0){
                    dfs(grid, vist, i , j, del_row, del_col) ;   
                    cnt++   ;    
                }
            }
        }
        return cnt ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna