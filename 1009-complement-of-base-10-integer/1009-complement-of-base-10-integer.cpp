class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 0;
        int m = n ;
        if (n == 0){
            return 1;
        }
        while (m != 0){
            mask = ((mask << 1) | 1 );
            m = m >> 1;
        }
        int ans = (~ n ) & mask ;
        return ans ;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna