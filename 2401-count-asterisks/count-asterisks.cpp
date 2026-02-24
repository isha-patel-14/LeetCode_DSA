class Solution {
public:
    int countAsterisks(string s) {
        int count=0,bar=0;
        bool verticalBar=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='|'){
                bar++;
            }
            if(bar%2==0){
                if(s[i]=='*'){
                    count++;
                }
            }
        }
        return count;
    }
};