class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            int index=i;
            if(nums[i]>0){
                for(int step=0;step<nums[i];step++){
                    index=(index+1)%n;
                }
            }else if(nums[i]<0){
                for(int step=0;step<-nums[i];step++){
                    index=(index-1+n)%n;
                }
            }
            result[i]=nums[index];
        }
        return result;
    }
};
