class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first=nums[0];
        int min1=100, min2=100;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2){
                min2=nums[i];
            }
        }
        return first + min1 + min2;
    }
};