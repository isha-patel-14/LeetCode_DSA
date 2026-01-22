class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        while(true){
            bool isSorted=true;
            for(int i=0;i+1<n;i++){
                if(nums[i]>nums[i+1]){
                    isSorted=false;
                    break;
                }
            }
            if(isSorted)
                return count;

            int minSum=INT_MAX;
            int index=0;

            for(int i=0;i+1<n;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<minSum){
                    minSum=sum;
                    index=i;
                }
            }
            nums[index]=minSum;
            for(int i=index+1;i+1<n;i++){
                nums[i]=nums[i+1];
            }
            nums.pop_back();
            n--;
            count++;
        }
        return count;
    }
};