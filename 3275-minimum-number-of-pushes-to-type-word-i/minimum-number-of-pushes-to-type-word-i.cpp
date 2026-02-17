class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int res=0,count=1;
        while(n>0){
            int take=min(8,n);
            res+=take*count;
            n-=take;
            count++;
        }
        return res;
    }
};