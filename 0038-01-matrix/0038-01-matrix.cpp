class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size() ; 
        int col = mat[0].size() ; 
        vector<vector<int>>vist(row, vector<int>(col, 0)) ; 
        vector<vector<int>>dist(row, vector<int>(col, 0)) ; // the resultant matrix which we will return 
        queue<pair<pair<int, int >, int>> q; 
        for (int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0}) ; 
                    vist[i][j] = 1; 
                }
                else{
                    vist[i][j] = 0; 
                }
            }
        }
        int del_r[] = {-1, 0, 1, 0} ; 
        int del_c[] = {0, 1, 0, -1} ;

        while(!q.empty()){
            int r = q.front().first.first ; 
            int c = q.front().first.second ; 
            int steps = q.front().second ; 
            q.pop() ; 
            dist[r][c] = steps ;
            int new_r; 
            int new_c ; 

            for(int i = 0 ; i < 4 ; i++){
                new_r = del_r[i] + r ; 
                new_c = del_c[i] + c ; 

                if(new_r >= 0 && new_r < row && new_c >= 0 && new_c < col && vist[new_r][new_c] == 0){
                    q.push({{new_r ,new_c}, steps +1}) ; 
                    vist[new_r][new_c] = 1;
                }
            }
        }
        return dist ; 
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna