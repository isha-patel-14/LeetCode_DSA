class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<pair<double, double>> events;
        double totalArea = 0;

        for (auto &s : squares) {
            double y = s[1], l = s[2];
            events.push_back({y, l});
            events.push_back({y + l, -l});
            totalArea += l * l;
        }

        sort(events.begin(), events.end());

        double target = totalArea / 2.0;
        double currArea = 0;
        double currSlope = 0;

        for (int i = 0; i + 1 < events.size(); i++) {
            double y = events[i].first;
            currSlope += events[i].second;
            double nextY = events[i + 1].first;

            if (currSlope > 0) {
                double areaGain = currSlope * (nextY - y);
                if (currArea + areaGain >= target) {
                    return y + (target - currArea) / currSlope;
                }
                currArea += areaGain;
            }
        }
        return 0;
    }
};