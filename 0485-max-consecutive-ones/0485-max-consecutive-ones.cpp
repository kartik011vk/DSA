class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for (int i = 0 ; i < nums.size() ; i++){
            if(nums[i]== 1){
                count = count + 1;
                maxi = max(maxi, count);

            }
            else{
                count = 0 ; 
            }
        }
        return maxi ; 
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna