class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1){
            int ans=-1;
            for(int i=0;i<n;i++){
                int count=0;
                for(int j=0;j<n;j++){
                    if(nums[i]==nums[j]){
                        count++;
                    }
                }
                if(count==1){
                    ans=max(ans,nums[i]);
                }
            }
            return ans;
        }
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        int ans = -1;
        int countFirst = 0;
        for (int x : nums) {
            if (x == nums[0])
                countFirst++;
        }

        if (countFirst == 1)
            ans = max(ans, nums[0]);

        int countLast = 0;
        for (int x : nums) {
            if (x == nums[n - 1])
                countLast++;
        }

        if (countLast == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};