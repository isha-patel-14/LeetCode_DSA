class Solution {
public:
    struct Trie {
        Trie* next[26];
        Trie() {
            for(int i=0;i<26;i++) next[i] = NULL;
        }
    };

    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        const int INF = 1e9;

        Trie* root = new Trie();

        // Build trie
        for (int i = 0; i < words.size(); i++) {
            Trie* node = root;
            for (char c : words[i]) {
                int idx = c - 'a';
                if (!node->next[idx])
                    node->next[idx] = new Trie();
                node = node->next[idx];
            }
        }

        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == INF) continue;

            Trie* node = root;

            for (int j = i; j < n; j++) {
                int idx = target[j] - 'a';
                if (!node->next[idx]) break;

                node = node->next[idx];

                dp[j + 1] = min(dp[j + 1], dp[i] + 1);
            }
        }

        return dp[n] == INF ? -1 : dp[n];
    }
};