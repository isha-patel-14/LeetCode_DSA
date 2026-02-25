class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         vector<int> que;
//         for(int i = nums.size() - 1; i >= 0; i--){
//             que.push_back(nums[i]);
//         }
//         return que[k - 1];
//     }
// };

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         return nums[n - k];
//     }
// };