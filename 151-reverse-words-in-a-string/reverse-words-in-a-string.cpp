// consists of different methods 

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans="";
        for(int i=0;i<s.length();i++){
            string revStr="";
            while (i < s.length() && s[i] == ' ')
                i++;
            while(i<s.length() && s[i]!=' '){
                revStr+=s[i];
                i++;
            }
            reverse(revStr.begin(),revStr.end());
            if(revStr.length()!=0){
                if (!ans.empty())
                    ans += " ";
                ans+=revStr;
            }
        }
        return ans.substr();
    }
};





// 2 pointer from end --> method
// class Solution {
// public:
//     string reverseWords(string s) {
//         string result = "";
//         int i =s.size()-1;
//         while(i>=0){
//             while (i>=0 && s[i]== ' ')
//                 i--;

//             if(i<0) break;

//             int j=i;

//             while(i>=0 && s[i]!=' ')
//                 i--;
//                 if(!result.empty())
//                     result+=" ";
//                     result+=s.substr(i+1,j-i);
//         }

//         return result;
//     }
// };