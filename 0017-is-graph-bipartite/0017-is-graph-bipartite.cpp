class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> colour(n, -1);

        queue<int> q;

        for(int i = 0; i < n; i++) {

            if(colour[i] == -1) {

                q.push(i);
                colour[i] = 0;

                while(!q.empty()) {

                    int node = q.front();
                    q.pop();

                    for(auto it : graph[node]) {

                        if(colour[it] == -1) {

                            colour[it] = 1 - colour[node];
                            q.push(it);

                        }
                        else if(colour[it] == colour[node]) {

                            return false;

                        }
                    }
                }
            }
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna