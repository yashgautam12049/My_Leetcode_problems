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
        vector<TreeNode*>v;
        void tra(TreeNode* &root,set<int>st){
            if(!root) return;
            if(root){
                tra(root->left,st);
            tra(root->right,st);
            if(st.find(root->val)!=st.end()){
                if(root->left)v.push_back(root->left);
                if(root->right)v.push_back(root->right);
                root=NULL;
                delete root;
            }
            }
            // v.push_back(root);
            

        }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>st(to_delete.begin(),to_delete.end());
        tra(root,st);
        if(root){
            v.push_back(root);
        }
        return v;
    }
};