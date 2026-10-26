class Solution {
public:

    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, int del_row[], int del_col[], int sr, int sc, int color, int ini_color){
        int row = image.size(); 
        int col = image[0]. size() ; 
        ans[sr][sc] = color  ; 
        for(int i = 0 ; i < 4 ; i++){
            int n_row = sr + del_row[i] ; 
            int n_col = sc + del_col[i] ; 
            if(n_row >= 0 && n_row < row && n_col >= 0 && n_col < col && image[n_row][n_col] == ini_color && ans[n_row][n_col] != color){
                dfs(image, ans, del_row, del_col, n_row, n_col, color, ini_color) ; 
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image ; 
        int ini_color = image[sr][sc] ;
        
        if (ini_color == color) {
            return image;
        }
 
        int del_row[4] = {-1, 0, 1, 0} ; 
        int del_col[4] = {0, 1, 0, -1} ; 
        dfs(image, ans, del_row, del_col, sr, sc, color, ini_color ) ; 
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna