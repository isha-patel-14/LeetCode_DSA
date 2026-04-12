class Solution {
public:

    int dp[301][27][27];

    int getDist(int a, int b) {
        if (a == 26) return 0;

        int x1 = a / 6, y1 = a % 6;
        int x2 = b / 6, y2 = b % 6;

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int i, int f1, int f2) {

        if (i == word.size()) return 0;

        if (dp[i][f1][f2] != -1) return dp[i][f1][f2];

        int curr = word[i] - 'A';

        int cost1 = getDist(f1, curr) + solve(word, i + 1, curr, f2);

        int cost2 = getDist(f2, curr) + solve(word, i + 1, f1, curr);

        if (cost1 < cost2) {
            dp[i][f1][f2] = cost1;
        } else {
            dp[i][f1][f2] = cost2;
        }

        return dp[i][f1][f2];
    }

    int minimumDistance(string word) {

        int i, j, k;

        for (i = 0; i < 301; i++) {
            for (j = 0; j < 27; j++) {
                for (k = 0; k < 27; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }

        return solve(word, 0, 26, 26);
    }
};