class Solution {
public:
    int findMin(vector<int>& nums) {

        int n = nums.size(); 
        int low = 0 ; 
        int high = n -1 ; 
        int mini = INT_MAX ; 
        while (low<= high){
            
            int mid =  ( low + high ) / 2 ; 
            if (low == high){
                mini = min(mini , nums[low]) ; 
            }
            if (nums[mid] == nums[low] && nums[high] == nums[mid]){
                mini = min(mini , nums[mid]) ; 
                low++ ; 
                high-- ; 
                continue ; 
            }
            if (nums[low]< nums[high]){

                mini = min(mini , nums[low]) ; 
                
                break ; 
            }
            if (nums[low]<= nums[mid]){
                mini = min(mini , nums[low]) ;
                low = mid+1 ; 
            }

            else{

                mini = min(mini , nums[mid]) ;
                high = mid -1 ; 
                
            }

        }
        return mini ;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna