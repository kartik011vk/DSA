class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x% 10 == 0 && x != 0)){
            return false ; 
        }
        int rem ; 
        int temp = x ; 
        long long  rev = 0 ; 
        while(x > 0){
            rem = x % 10 ; 
            rev = rev *10 + rem ; 
            x = x /10 ; 
        }

        if(temp == rev){
            return true ; 
        }
        else{
            return false ;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna