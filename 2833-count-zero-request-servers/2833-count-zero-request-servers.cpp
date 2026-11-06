
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        int m = logs.size();
        int q = queries.size();

        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> qu;

        for(int i = 0; i < q; i++) {
            qu.push_back({queries[i], i});
        }

        sort(qu.begin(), qu.end());

        vector<int> ans(q);
        vector<int> freq(n + 1, 0);

        int left = 0, right = 0;
        int active = 0;

        for(auto &query : qu) {

            int time = query.first;
            int idx = query.second;

            int start = time - x;

            while(right < m && logs[right][1] <= time) {

                int server = logs[right][0];

                if(freq[server] == 0)
                    active++;

                freq[server]++;
                right++;
            }

            while(left < right && logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if(freq[server] == 0)
                    active--;

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna