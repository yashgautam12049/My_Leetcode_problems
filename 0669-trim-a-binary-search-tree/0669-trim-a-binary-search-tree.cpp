/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, int low, int high) {
        if (!root)
            return NULL;
        TreeNode* left_n = solve(root->left, low, high);
        if (left_n != root->left) {
            root->left = left_n;
        }
        TreeNode* right_n = solve(root->right, low, high);
        if (right_n != root->right) {
            root->right = right_n;
        }
        if (root->val < low || root->val > high) {
            return root->left ? root->left : root->right;
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};