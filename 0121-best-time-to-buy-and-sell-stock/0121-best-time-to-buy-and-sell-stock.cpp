class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0 ; 
        for (int i = 0 ; i< prices.size(); i++){
            int cost = prices[i] - mini ;
            profit = max(profit, cost) ; 
            mini = min(mini, prices[i]);
        }
        return profit ; 
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna