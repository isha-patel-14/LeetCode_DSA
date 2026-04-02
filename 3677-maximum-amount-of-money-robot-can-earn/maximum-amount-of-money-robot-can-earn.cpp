class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(),n=coins[0].size();
        vector<vector<vector<long long>>> dp(
            m,vector<vector<long long>>(n,vector<long long>(3,LLONG_MIN))
        );
        dp[0][0][0] = coins[0][0];

        if (coins[0][0] < 0) {
            dp[0][0][1] = 0;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                for (int k = 0; k <= 2; k++) {

                    if (i == 0 && j == 0) continue;

                    long long best = LLONG_MIN;

                    if (i > 0) {
                        best = max(best, dp[i - 1][j][k]);
                    }

                    if (j > 0) {
                        best = max(best, dp[i][j - 1][k]);
                    }

                    if (best != LLONG_MIN) {
                        dp[i][j][k] = max(dp[i][j][k], best + coins[i][j]);
                    }

                    if (coins[i][j] < 0 && k > 0) {

                        long long best2 = LLONG_MIN;

                        if (i > 0) {
                            best2 = max(best2, dp[i - 1][j][k - 1]);
                        }

                        if (j > 0) {
                            best2 = max(best2, dp[i][j - 1][k - 1]);
                        }

                        if (best2 != LLONG_MIN) {
                            dp[i][j][k] = max(dp[i][j][k], best2);
                        }
                    }
                }
            }
        }

        long long ans = max(dp[m - 1][n - 1][0],
                      max(dp[m - 1][n - 1][1],
                          dp[m - 1][n - 1][2]));

        return (int)ans;
    }
};