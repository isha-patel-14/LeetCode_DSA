// Time	-> O(n log n)
// Space -> O(log n)
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int minPositive=1;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==minPositive){
//                 minPositive++;
//             }
//             if(nums[i]>minPositive)
//                 return minPositive;
//         }
//         return minPositive;
//     }
// };


// Time	-> O(n)
// Space -> O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (
                nums[i]>0 && nums[i]<=n && nums[nums[i] - 1] != nums[i]) {
                    swap(nums[i], nums[nums[i] - 1]);
                }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
