class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int freq[26] = {0};
        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        int count = 0;
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) {
                count = freq[i];
                break;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0 && freq[i] != count) {
                return false;
            }
        }
        return true;
    }
};
