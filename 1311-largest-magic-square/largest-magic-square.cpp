class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> rowSum(m, vector<long long>(n + 1, 0));
        vector<vector<long long>> colSum(m + 1, vector<long long>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i][j + 1] = rowSum[i][j] + grid[i][j];
                colSum[i + 1][j] = colSum[i][j] + grid[i][j];
            }
        }

        int maxK = min(m, n);

        for (int k = maxK; k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {

                    long long target =
                        rowSum[i][j + k] - rowSum[i][j];

                    bool ok = true;

                    for (int r = i; r < i + k && ok; r++) {
                        long long sum =
                            rowSum[r][j + k] - rowSum[r][j];
                        if (sum != target) ok = false;
                    }

                    for (int c = j; c < j + k && ok; c++) {
                        long long sum =
                            colSum[i + k][c] - colSum[i][c];
                        if (sum != target) ok = false;
                    }

                    long long d1 = 0, d2 = 0;
                    for (int t = 0; t < k; t++) {
                        d1 += grid[i + t][j + t];
                        d2 += grid[i + t][j + k - 1 - t];
                    }

                    if (d1 != target || d2 != target) ok = false;

                    if (ok) return k;
                }
            }
        }

        return 1;
    }
};
