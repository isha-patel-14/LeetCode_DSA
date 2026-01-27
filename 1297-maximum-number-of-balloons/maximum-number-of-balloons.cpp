class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0, a=0, l2=0, o2=0, n=0;
            
        for(int i=0;i<text.size();i++){
            if(text[i]=='b') b++;
            else if(text[i]=='a') a++;
            else if(text[i]=='l') l2++;
            else if(text[i]=='o') o2++;
            else if(text[i]=='n') n++;
        }
        l2=l2/2;  o2=o2/2;
        int ans=min({b, a, l2, o2, n});
        return ans;
    }
};