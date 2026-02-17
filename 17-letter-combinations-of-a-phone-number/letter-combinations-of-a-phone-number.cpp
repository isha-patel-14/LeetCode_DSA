class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string> mapping={"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>result={""};
        for(int i=0;i<digits.size();i++){
            vector<string>temp;
            string letters=mapping[digits[i]-'0'];
            for(int j=0;j<result.size();j++){
                for(int k=0;k<letters.size();k++){
                    temp.push_back(result[j]+letters[k]);
                }
            }
            result=temp;
        }
        return result;
    }
};