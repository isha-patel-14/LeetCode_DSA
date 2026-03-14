class Solution {
public:
    string greatestLetter(string s) {
        for(char c='Z';c>='A';c--){
            bool upper=false;
            bool lower=false;
            for(int i=0;i<s.size();i++){
                if(s[i]==c){
                    upper=true;
                }
                if(s[i]==c+32){
                    lower=true;
                }
            }
            if(upper && lower){
                return string(1,c);
            }
        }
        return "";
    }
};