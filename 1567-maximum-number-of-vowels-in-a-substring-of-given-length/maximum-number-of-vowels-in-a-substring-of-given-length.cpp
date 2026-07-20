class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int count=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i]))
                count++;
        }
        int ans=count;
        int left=0;
        for(int right=k;right<s.size();right++){
            if(isVowel(s[left]))
                count--;
                left++;

            if(isVowel(s[right]))
                count++;
                
            ans=max(ans,count);
        }
        return ans;
    }
};