class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool upper[26]={false};
        bool lower[26]={false};
        for(int i=0;i<word.size();i++){
            if(word[i]>='a' && word[i]<='z'){
                lower[word[i]-'a']=true;
            }else{
                upper[word[i]-'A']=true;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(lower[i]&&upper[i]){
                count++;
            }
        }
        return count;
    }
};