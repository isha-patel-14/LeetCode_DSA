class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum;
        vector<int> rightSum;
        vector<int> ans;
        int rSum=0,lSum=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            leftSum.push_back(lSum);
            lSum+=nums[i];
        }

        for(int i=n-1;i>=0;i--){
            rightSum.push_back(rSum);
            rSum+=nums[i];
        }
        reverse(rightSum.begin(),rightSum.end());

        for(int i=0;i<n;i++){
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }
        return ans;
    }
};