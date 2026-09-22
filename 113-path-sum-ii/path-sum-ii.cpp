/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    void solve(TreeNode* root, int targetSum, vector<int>& path) {
        if (root == NULL)
            return;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == root->val) {
                result.push_back(path);
            }
        }
        else {
            solve(root->left, targetSum - root->val, path);
            solve(root->right, targetSum - root->val, path);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, path);
        return result;
    }
};