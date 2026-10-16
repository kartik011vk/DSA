class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans ; 
        int n  = nums.size() ; 
  
        for(int i = 0 ;i < n ; i++ ){
            if(nums[i] == target){
                ans.push_back(i) ;
            }
            
        }
        if(ans.empty()){
            return {-1, -1} ; 
        }
        return ans ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna