class Solution {
    multiset<long long> left, right;
    long long leftSum = 0, rightSum = 0;

    // Add an element
    void addValue(long long val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            leftSum += val;
        } else {
            right.insert(val);
            rightSum += val;
        }
    }

    // Remove an element
    void removeValue(long long val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            leftSum -= val;
        } else {
            auto it2 = right.find(val);
            right.erase(it2);
            rightSum -= val;
        }
    }

    // Balance both multisets
    void rebalance(int target) {
        while (left.size() > target) {
            auto it = prev(left.end());
            long long val = *it;

            left.erase(it);
            leftSum -= val;

            right.insert(val);
            rightSum += val;
        }

        while (left.size() < target) {
            auto it = right.begin();
            long long val = *it;

            right.erase(it);
            rightSum -= val;

            left.insert(val);
            leftSum += val;
        }

        // Ensure every element in left <= every element in right
        while (!left.empty() && !right.empty() &&
               *left.rbegin() > *right.begin()) {

            long long a = *left.rbegin();
            long long b = *right.begin();

            left.erase(prev(left.end()));
            right.erase(right.begin());

            left.insert(b);
            right.insert(a);

            leftSum += b - a;
            rightSum += a - b;
        }
    }

    // Calculate operations needed for the current window
    long long getCost() {
        long long median = *left.rbegin();

        return median * left.size() - leftSum
             + rightSum - median * right.size();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        left.clear();
        right.clear();
        leftSum = 0;
        rightSum = 0;

        // Build the first window
        for (int i = 0; i < x; i++) {
            left.insert(nums[i]);
            leftSum += nums[i];
        }

        int target = (x + 1) / 2;
        rebalance(target);

        // Store the cost of every window
        vector<long long> cost(n - x + 1);

        cost[0] = getCost();

        for (int i = 1; i <= n - x; i++) {
            removeValue(nums[i - 1]);
            addValue(nums[i + x - 1]);

            rebalance(target);

            cost[i] = getCost();
        }

        // Dynamic programming
        const long long INF = (1LL << 60);

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        // Zero subarrays require zero operations
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                // Option 1: Skip the current element
                dp[j][i] = dp[j][i - 1];

                // Option 2: Select a window ending at i-1
                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna