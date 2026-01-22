class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minPositive=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minPositive){
                minPositive++;
            }
            if(nums[i]>minPositive)
                return minPositive;
        }
        return minPositive;
    }
};