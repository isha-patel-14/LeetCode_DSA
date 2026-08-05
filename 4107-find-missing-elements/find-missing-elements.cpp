class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=nums[0];i<=nums[nums.size()-1];i++){
            if(j<nums.size()&&i==nums[j]){
                j++;
            }else{
                ans.push_back(i);
            }
        }
        return ans;
    }
};