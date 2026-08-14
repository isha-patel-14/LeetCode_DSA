class Solution {
public:
    string reverseOnlyLetters(string s) {
        string letters;
        for(char c:s){
            if(isalpha(c)){
                letters+=c;
            }
        }
        reverse(letters.begin(),letters.end());
        int index=0;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])){
                s[i]=letters[index++];
            }
        }
        return s;
    }
};