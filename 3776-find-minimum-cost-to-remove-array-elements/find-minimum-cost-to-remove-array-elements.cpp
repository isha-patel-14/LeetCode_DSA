class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int min_cost(vector<int>& nums , int first , int level){
        if(level == n)
        {
            return nums[first];
        }

        if(level == n - 1)
        {
            return max(nums[level] , nums[first]);
        }

        if(dp[level][first] != -1)
        {
            return dp[level][first];
        }

        int ans = INT_MAX;
        ans = min(ans , max(nums[first] , nums[level]) + min_cost(nums , level + 1 , level + 2));

        ans = min(ans , max(nums[first] , nums[level + 1]) + min_cost(nums , level , level + 2));

        ans = min(ans , max(nums[level] , nums[level + 1]) + min_cost(nums , first , level + 2));

        return dp[level][first] = ans;
    }
    int minCost(vector<int>& nums) {
        n = nums.size();
        dp.resize(n + 1 , vector<int> (n + 1 , -1));

        int ans = min_cost(nums , 0 , 1);
        return ans;
    }
};