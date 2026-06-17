class Solution {
public:
    int subtractProductAndSum(int n) {

        int product = 1;
        int sum = 0;
        while (n != 0){
            int rem  = n % 10 ;

            sum = sum +rem ;
            product = product * rem ;

            n = n /10;
        }
        int result = product - sum ;
        return result ;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna