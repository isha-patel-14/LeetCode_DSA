class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n=s.size(), totOccur=0;
        for(int i=0;i<n;i++){
            if(s[i]==letter){
                totOccur++;
            }
        }
        int result=totOccur*100;
        result=result/n;
        return result;
    }
};