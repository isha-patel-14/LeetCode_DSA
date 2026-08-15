class Solution {
public:
    string findValidPair(string s) {
        vector<int> freq(10, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - '0']++;
        }
        string ans = "";
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] != s[i + 1] && freq[s[i] - '0'] == (s[i] - '0') &&
                freq[s[i + 1] - '0'] == (s[i + 1] - '0')) {
                ans += s[i];
                ans += s[i + 1];
                return ans;
            }
        }
        return "";
    }
};