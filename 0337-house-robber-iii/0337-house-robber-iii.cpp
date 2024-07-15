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
    pair<int,int> check(TreeNode* root){
        // int a=0,b=0;
        if(root==NULL)return {0,0};
        pair<int,int> left=check(root->left);
        pair<int,int> right=check(root->right);
        int pick=root->val+left.second+right.second;
        int not_pick=max(left.first,left.second)+max(right.first,right.second);
        return {pick,not_pick};
    }
    int rob(TreeNode* root) {
        pair<int,int>v=check(root);
        return max(v.first,v.second);
    }
};