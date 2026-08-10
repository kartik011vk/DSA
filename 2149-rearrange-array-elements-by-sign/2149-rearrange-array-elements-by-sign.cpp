class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size()); 
        int pos_index = 0; 
        int neg_index = 1; 
       
        for (int i = 0 ; i < nums.size(); i++){
            if (nums[i]> 0 ){
                ans[pos_index] = nums[i] ; 
                pos_index = pos_index + 2 ;
            }
            else{
                ans[neg_index] = nums[i];
                neg_index = neg_index + 2 ;
            }
        }
       
        return ans ; 
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna