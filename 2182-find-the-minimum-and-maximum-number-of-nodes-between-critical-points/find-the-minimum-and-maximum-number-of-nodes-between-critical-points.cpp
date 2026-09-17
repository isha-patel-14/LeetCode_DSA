/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
        vector<int>points;
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                points.push_back(i);
            }else if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                points.push_back(i);
            }
        }
        int m=points.size();
        if(m<2) return {-1,-1};
        int minDist=INT_MAX;
        int maxDist=points[m-1]-points[0];
        for(int i=1;i<m;i++){
            minDist=min(minDist,points[i]-points[i-1]);
        }
        return {minDist,maxDist};
    }
};