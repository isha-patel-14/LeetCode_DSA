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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> nums;
        ListNode* temp = head;
        while (temp) {
            nums.push_back(temp->val);
            temp = temp->next;
        }
        int n = nums.size();
        int first = k - 1;
        int second = n - k;
        swap(nums[first], nums[second]);
        temp = head;
        for (int i = 0; i < n; i++) {
            temp->val = nums[i];
            temp = temp->next;
        }
        return head;
    }
};