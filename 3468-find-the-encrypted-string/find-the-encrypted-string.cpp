class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n=s.size();
        k=k%n;
        string result;
        for(int i=0;i<n;i++){
            int index=(i+k)%n;
            result+=s[index];
        }
        return result;
    }
};