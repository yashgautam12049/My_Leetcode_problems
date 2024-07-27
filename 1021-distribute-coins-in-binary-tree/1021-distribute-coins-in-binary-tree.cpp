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
    int move=0;
    int check(TreeNode* root){
        if (root == NULL)
            return 0;
        int l = check(root->left);
        int r = check(root->right);
        move += (abs(l) + abs(r));
        return root->val + l + r - 1;
    }
    int distributeCoins(TreeNode* root) {
        check(root);
        return move;
    }
};