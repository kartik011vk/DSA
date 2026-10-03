class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() ; 
        int low = 0; 
        int high = n - 1 ;
        while(low<= high){

            int mid = (low+high) / 2 ; 
            if(nums[mid] == target){
                return mid ; 
            }

            if(nums[low]<= target && nums[mid ] > target){

                high = mid -1 ; 
            }
            else{
                low = mid + 1 ; 
            }
        }
        return -1 ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna