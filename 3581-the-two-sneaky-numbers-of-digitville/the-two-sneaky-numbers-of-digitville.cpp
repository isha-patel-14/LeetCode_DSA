class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> arr;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    arr.push_back(nums[i]);
                    break;
                }
            }
        }
        return arr;
    }
};