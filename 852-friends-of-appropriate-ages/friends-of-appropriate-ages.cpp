class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int>cnt(121,0);
        for(int i=0;i<ages.size();i++){
            cnt[ages[i]]++;
        }
        vector<int>prefix(121,0);
        for(int i=1;i<=120;i++){
            prefix[i]=prefix[i-1]+cnt[i];
        }
        int ans=0;
        for(int age=15;age<=120;age++){
            if(cnt[age]==0)
                continue;
            int minAge=age/2+8;
            int eligible=prefix[age]-prefix[minAge-1];
            ans+=cnt[age]*(eligible-1);
        }
        return ans;
    }
};