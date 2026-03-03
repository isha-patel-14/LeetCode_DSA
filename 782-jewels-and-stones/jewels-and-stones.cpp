class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count=0;
        for(int i=0;i<jewels.length();i++){
            char j=jewels[i];
            for(int k=0;k<stones.length();k++){
                char s=stones[k];
                if(j==s){
                    count++;
                }
            }
        }
        return count;
    }
};
