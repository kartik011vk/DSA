class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long sum = 0 ; 
        sort(nums.begin() , nums.end(), [](int a , int b)
        {return abs(a)< abs(b) ; 
        }) ; 
        int n = nums.size() ; 
        for (int i = 0 ; i< n/2 ; i++){
            sum = sum - (1LL * nums[i] * nums[i]) ; 
        }
        for (int i = n/2 ; i < n; i++){
            sum = sum + (1LL * nums[i] * nums[i]); 
        }
        return sum ; 
    }
    
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna