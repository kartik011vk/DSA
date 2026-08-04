class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int > mpp ; 
        int n = nums.size();
        for(int i = 0 ; i< n; i++){
            int num = nums[i];
            int remain = target - num ; 
            if(mpp.find(remain) != mpp.end()){
                return {mpp[remain], i}; 
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna