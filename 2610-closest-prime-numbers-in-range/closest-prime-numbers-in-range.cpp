class Solution {
public:
    bool prime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int prev=-1, first=-1, second=-1, minDiff=INT_MAX;
        for(int i=left;i<=right;i++){
            if(prime(i)){
                if(prev!= -1){
                    if(i-prev<minDiff){
                        minDiff=i-prev;
                        first=prev;
                        second=i;
                    }
                }
                prev=i;
            }
        }
        return{first,second};
    }
};