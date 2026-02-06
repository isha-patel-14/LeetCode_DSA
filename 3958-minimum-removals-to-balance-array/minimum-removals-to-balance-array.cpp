class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j = 0;
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            while (j < n && (long long)nums[j] <= (long long)nums[i] * k) {
                j++;
            }
            maxLen = max(maxLen, j - i);
        }
        return n - maxLen;
    }
};