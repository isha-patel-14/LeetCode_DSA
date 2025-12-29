class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0 , maxCount=0;

        for(int x:nums){
            if (x==1){
                curr++;
                maxCount=max(maxCount,curr);
            }
            else{
                curr=0;
            }
        }
        return maxCount;
    }
};