class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {

            if (n % k != 0)
                continue;

            vector<int> arr = nums;
            bool possible = true;

            for (int i = 0; i < n; i += k) {

                int drops = 0;

                for (int j = i; j < i + k - 1; j++) {
                    if (arr[j] > arr[j + 1])
                        drops++;
                }

                if (arr[i + k - 1] > arr[i])
                    drops++;

                if (drops > 1) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                for (int i = 0; i < n; i += k) {
                    int smallest = i;

                    for (int j = i + 1; j < i + k; j++) {
                        if (arr[j] < arr[smallest])
                            smallest = j;
                    }

                    rotate(arr.begin() + i,
                           arr.begin() + smallest,
                           arr.begin() + i + k);
                }

                if (is_sorted(arr.begin(), arr.end()))
                    ans += k;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna