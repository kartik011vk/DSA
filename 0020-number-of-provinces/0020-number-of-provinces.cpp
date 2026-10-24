class Solution {
public:

    void dfs(int node, vector<vector<int>> &adj ,vector<int> &vist ){
        vist[node] = 1;   
        for(auto it : adj[node]){
            if(!vist[it]){
                dfs(it, adj,vist ) ; 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =  isConnected.size() ;
        int cnt = 0 ; 
        vector<int> vist(n, 0);
        vector<vector<int>> adj(n) ; 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j) ; 
                    adj[j].push_back(i) ; 
                }
            }
        }
        for(int k = 0 ; k < adj.size() ; k++){
            if(vist[k] == 0 ){
                dfs(k, adj, vist) ; 
                cnt++ ; 
            }
        }
        return cnt ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna