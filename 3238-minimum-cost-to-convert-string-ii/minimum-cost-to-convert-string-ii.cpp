class Solution {
public:
    struct TrieNode {
        int id;
        TrieNode* child[26];
        TrieNode() {
            id = -1;
            for(int i = 0; i < 26; i++) child[i] = NULL;
        }
    };

    void insert(TrieNode* root, string &s, int idx) {
        TrieNode* cur = root;
        for(int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if(cur->child[c] == NULL) cur->child[c] = new TrieNode();
            cur = cur->child[c];
        }
        cur->id = idx;
    }

    long long minimumCost(string source, string target,
                          vector<string>& original,
                          vector<string>& changed,
                          vector<int>& cost) {

        long long INF = 1e18;
        int n = source.size();

        unordered_map<string,int> mp;
        int idx = 0;

        for(int i = 0; i < original.size(); i++) {
            if(!mp.count(original[i])) mp[original[i]] = idx++;
            if(!mp.count(changed[i])) mp[changed[i]] = idx++;
        }

        vector<vector<long long>> dist(idx, vector<long long>(idx, INF));
        for(int i = 0; i < idx; i++) dist[i][i] = 0;

        for(int i = 0; i < cost.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for(int k = 0; k < idx; k++) {
            for(int i = 0; i < idx; i++) {
                for(int j = 0; j < idx; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        TrieNode* root = new TrieNode();
        vector<string> words(idx);

        for(auto &p : mp) {
            words[p.second] = p.first;
        }

        for(int i = 0; i < idx; i++) {
            insert(root, words[i], i);
        }

        vector<long long> dp(n + 1, INF);
        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--) {

            if(source[i] == target[i])
                dp[i] = dp[i + 1];

            TrieNode* curS = root;

            for(int j = i; j < n; j++) {

                int cs = source[j] - 'a';
                if(curS->child[cs] == NULL) break;

                curS = curS->child[cs];

                if(curS->id != -1) {

                    int u = curS->id;
                    int len = j - i + 1;

                    string subT = target.substr(i, len);

                    if(mp.count(subT)) {
                        int v = mp[subT];

                        if(dist[u][v] != INF && dp[j + 1] != INF) {
                            dp[i] = min(dp[i], dist[u][v] + dp[j + 1]);
                        }
                    }
                }
            }
        }

        return (dp[0] == INF) ? -1 : dp[0];
    }
};
