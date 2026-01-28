class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;
        for(int i=0;i<columnTitle.size();i++){
            int value=columnTitle[i]-'A'+1;
            result=result*26+value;
        }
        return result;
    }
};
