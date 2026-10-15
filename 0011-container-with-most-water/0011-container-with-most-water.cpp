class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 ; 
        int j = height.size() -1 ; 
        int ans = 0 ; 
        while(i<j){

            int width = j - i ; 
            
            int h = min(height[i], height[j]) ; 
            int area = h * width ; 

            ans = max(ans, area); 
            if(height[i] < height[j]){
                i ++ ; 
            }
            else{
                j-- ; 
            }
        }
        return ans ; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna