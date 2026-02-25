// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
        
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> que;
        for(int i = nums.size() - 1; i >= 0; i--){
            que.push_back(nums[i]);
        }
        return que[k - 1];
    }
};

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         return nums[n - k];
//     }
// };