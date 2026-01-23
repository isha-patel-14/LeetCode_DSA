class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            string temp = words[i];
            reverse(words[i].begin(), words[i].end());
            if(temp == words[i])
                return words[i];
        }
        return "";
    }
};

// class Solution {
// public:
//     string firstPalindrome(vector<string>& words) {
//         for (int i=0;i<words.size();i++){
//             string s=words[i];
//             string rev="";

//             for(int j=s.length()-1;j>=0;j--){
//                 rev+=s[j];
//             }

//             if(s==rev) {
//                 return s;
//             }
//         }
//         return "";
//     }
// };
