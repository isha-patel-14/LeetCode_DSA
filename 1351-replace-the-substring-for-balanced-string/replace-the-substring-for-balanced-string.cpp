class Solution {
public:
    int balancedString(string s) {
        int n=s.size();
        int k=n/4;
        vector<int>count(128,0);
        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        if(count['Q']==k && count['W']==k && count['E']==k && count['R']==k)
            return 0;
        int res=n;
        int i=0;
        for(int j=0;j<n;j++){
            count[s[j]]--;
            while(i<=j && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k){
                res=min(res,j-i+1);
                count[s[i]]++;
                i++;
            }
        }
        return res;
    }
};