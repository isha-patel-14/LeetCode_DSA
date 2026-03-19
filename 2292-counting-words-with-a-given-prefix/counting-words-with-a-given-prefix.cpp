class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(int i = 0; i < words.size(); i++) {
            if(words[i].size() < pref.size())
                continue;
            bool match = true;
            for(int j = 0; j < pref.size(); j++) {
                if(words[i][j] != pref[j]) {
                    match = false;
                    break;
                }
            }
            if(match)
                count++;
        }
        return count;
    }
};