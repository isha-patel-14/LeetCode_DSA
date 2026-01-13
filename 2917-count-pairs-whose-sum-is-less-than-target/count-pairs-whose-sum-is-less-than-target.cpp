class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count=0;
        int left=0;
        int right=nums.size()-1;

        while(left < right) {
            int currentSum = nums[left] + nums[right];
            if (currentSum < target) {
                count+=(right-left);
                left++;
            }else{
                right--;
            }
        }
        return count;
    }
};



// class Solution {
// public:
//     int countPairs(vector<int>& nums, int target) {
//         int count=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]+nums[j]<target && i<j){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };