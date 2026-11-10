class Solution {
public:
    int carFleet(int target, vector<int>& position,
                 vector<int>& speed) {

        int n = position.size();

        
        vector<pair<int,int>> cars;

        for(int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }


        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double prevTime = 0;


        for(int i = 0; i < n; i++) {

            int pos = cars[i].first;
            int sp = cars[i].second;

            double currTime = (double)(target - pos) / sp;

            if(currTime > prevTime) {

                fleets++;

                prevTime = currTime;
            }
        }

        return fleets;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna