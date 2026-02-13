class Solution {
public:
    int singleRun(string &s) {
        int best = 1, cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) cur++;
            else cur = 1;
            best = max(best, cur);
        }
        return best;
    }

    int solvePair(string &s, char x, char y, char bad) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; ) {
            if (s[i] == bad) {
                i++;
                continue;
            }

            unordered_map<int,int> mp;
            mp[0] = -1;

            int diff = 0;
            int start = i;

            while (i < n && s[i] != bad) {
                if (s[i] == x) diff++;
                else if (s[i] == y) diff--;

                if (mp.count(diff))
                    ans = max(ans, i - (start + mp[diff]));
                else
                    mp[diff] = i - start;

                i++;
            }
        }

        return ans;
    }

    int solveTriple(string &s) {
        unordered_map<long long,int> mp;
        mp[0] = -1;

        int a = 0, b = 0, c = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;

            int d1 = a - b;
            int d2 = a - c;

            long long key = ((long long)d1 << 32) ^ (unsigned int)d2;

            if (mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        return ans;
    }

    int longestBalanced(string s) {
        int ans = singleRun(s);
        ans = max(ans, solvePair(s, 'a', 'b', 'c'));
        ans = max(ans, solvePair(s, 'a', 'c', 'b'));
        ans = max(ans, solvePair(s, 'b', 'c', 'a'));
        ans = max(ans, solveTriple(s));
        return ans;
    }
};