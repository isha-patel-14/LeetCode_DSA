class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<long long> maxDp(n);
        vector<long long> minDp(n);

        maxDp[0] = grid[0][0];
        minDp[0] = grid[0][0];

        // first row
        for (int j = 1; j < n; j++) {
            maxDp[j] = maxDp[j - 1] * grid[0][j];
            minDp[j] = maxDp[j];
        }

        for (int i = 1; i < m; i++) {

            maxDp[0] = maxDp[0] * grid[i][0];
            minDp[0] = maxDp[0];

            for (int j = 1; j < n; j++) {

                long long a = maxDp[j] * grid[i][j];
                long long b = minDp[j] * grid[i][j];
                long long c = maxDp[j - 1] * grid[i][j];
                long long d = minDp[j - 1] * grid[i][j];

                long long maxVal = max(max(a, b), max(c, d));
                long long minVal = min(min(a, b), min(c, d));

                maxDp[j] = maxVal;
                minDp[j] = minVal;
            }
        }

        long long result = maxDp[n - 1];

        if (result < 0) return -1;

        return (int)(result % 1000000007);
    }
};