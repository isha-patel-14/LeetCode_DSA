class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int size = m * n;

        vector<long long> flat(size);

        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                flat[idx++] = grid[i][j];
            }
        }

        vector<long long> result(size, 1);

        long long pref = 1;
        for (int i = 0; i < size; i++) {
            result[i] = pref;
            pref = (pref * flat[i]) % 12345;
        }

        long long suff = 1;
        for (int i = size - 1; i >= 0; i--) {
            result[i] = (result[i] * suff) % 12345;
            suff = (suff * flat[i]) % 12345;
        }

        vector<vector<int>> ans(m, vector<int>(n));

        idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = (int)result[idx++];
            }
        }

        return ans;
    }
};