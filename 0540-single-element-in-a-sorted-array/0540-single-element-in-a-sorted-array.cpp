class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        int low = 1 ; 
        int high = n - 2 ;
        if (n== 1){
            return nums[0] ; 
        } 
        if (nums[n-1]!= nums[n-2]){
            return nums[n-1] ;
        }
        if (nums[0] != nums[1]){

            return nums[0] ; 
        }
        
        while(low<= high){
            int mid = (low + high )/ 2 ; 
            if (nums[mid]!= nums[mid+1]&& nums[mid]!= nums[mid -1]){
                return nums[mid] ; 
            }

            if((mid%2 == 1 && nums[mid]== nums[mid-1]) || (mid%2 == 0 && nums[mid]== nums[mid+1])){
                low = mid + 1 ; 
            }
            else{

                high = mid - 1 ; 
            }
        }
        return -1 ; 
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna