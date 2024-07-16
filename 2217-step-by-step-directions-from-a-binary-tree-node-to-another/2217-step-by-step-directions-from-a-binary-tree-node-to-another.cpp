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
    TreeNode* lca(TreeNode* root, int startValue, int destValue){
        if(root==NULL) return NULL;
        if(root->val==startValue||root->val==destValue){
            return root;
        }
        TreeNode* isl=lca(root->left,startValue,destValue);
        TreeNode* isr=lca(root->right,startValue,destValue);
        if(isl!=NULL && isr!=NULL) return root;
        if(isl!=NULL) return isl;
        return isr;
    }
    bool path(TreeNode* root,int val,string &a){
        if(root==NULL) return 0;
        if(root->val==val) return 1;
        //explore left
        a.push_back('L');
        if(path(root->left,val,a)==true){
            return 1;
        }
        a.pop_back();
        a.push_back('R');
        if(path(root->right,val,a)==true){
            return 1;
        }
        a.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *baap=lca(root,startValue,destValue);
        string lca_s="";
        string lca_d="";
        path(baap,startValue,lca_s);
        path(baap,destValue,lca_d);
        string ans="";
        for(int i=0;i<lca_s.size();i++){
            ans.push_back('U');
        }
        return ans+lca_d;
    }
};