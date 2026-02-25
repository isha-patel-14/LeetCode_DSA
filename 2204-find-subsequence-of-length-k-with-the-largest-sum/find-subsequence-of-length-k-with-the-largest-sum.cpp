class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size(),i=0,t=k;
        vector<int>ans;
        while(t>0){
            ans.push_back(nums[i]);
            i++;
            t--;
        }
        for(int j=i;j<n;j++){
            int min1=min_element(ans.begin(),ans.end())-ans.begin();
            if(ans[min1]<nums[j]){
                ans.erase(ans.begin()+min1);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};