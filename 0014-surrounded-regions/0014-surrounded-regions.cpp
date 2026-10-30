class Solution {
public:


    void dfs(int row, int col, vector<vector<int>>& vist, vector<vector<char>>& board, int del_r[], int del_c[]){
        vist[row][col] = 1 ; 
        int n = board.size() ; 
        int m = board[0].size() ;
        int new_r ;
        int new_c ; 
        for(int i = 0; i< 4; i++){
            new_r = del_r[i] + row ; 
            new_c = del_c[i] + col ; 

            if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < m && !vist[new_r][new_c] && board[new_r][new_c] == 'O'){
                dfs(new_r, new_c, vist, board, del_r, del_c) ; 
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size() ; 
        int m = board[0].size() ; 
        vector<vector<int>>vist(n, vector<int>(m, 0)) ;
        int del_r[] = {-1, 0, 1, 0} ; 
        int del_c[] = {0, 1, 0, -1} ; 

        for(int i = 0 ; i < m ; i++){
            if(!vist[0][i] && board[0][i] == 'O'){
                dfs(0, i, vist, board, del_r, del_c) ; 
            }

            if(!vist[n-1][i] && board[n-1][i] == 'O'){
                dfs(n-1, i, vist, board, del_r, del_c ) ; 
            }
        }

        for(int j = 0 ; j < n ; j++){

            if(!vist[j][0] && board[j][0] == 'O'){
                dfs(j , 0, vist, board, del_r, del_c) ; 
            }

            if(!vist[j][m-1] && board[j][m-1]== 'O'){
                dfs(j, m-1, vist, board, del_r, del_c) ; 
            }
        }


        for(int i = 0 ; i< n ; i++ ){
            for(int j = 0 ; j < m ; j++){
                if(!vist[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X'; 
                    
                }
            }
        }
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna