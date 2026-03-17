class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int max = nums[0], min = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
            if (nums[i] < min) {
                min = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != min && nums[i] != max) {
                return nums[i];
                break;
            }
        }
        return -1;
    }
};