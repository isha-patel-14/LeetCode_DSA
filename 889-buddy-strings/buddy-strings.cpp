class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int first=-1,second=-1,diff=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=goal[i]){
                diff++;
                if(diff==1)first=i;
                else if(diff==2)second=i;
                else return false;
            }
        }
        if(diff==2){
            return s[first]==goal[second] && s[second]==goal[first]; 
        }
        if(diff==0){
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
                if (freq[c - 'a'] > 1) return true;
            }
        }
        return false;
    }
};