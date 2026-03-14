class Solution {
public:
    string ans="";
    int count=0;
    void backtrack(int n,int k,string curr){
        if(curr.size()==n){
            count++;
            if(count==k)
                ans=curr;
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(curr.size()>0 && curr.back()==ch)
                continue;
            backtrack(n,k,curr+ch);
            if(ans!="")
                return;
        }
    }
    string getHappyString(int n, int k){
        backtrack(n,k,"");
        return ans;
    }
};