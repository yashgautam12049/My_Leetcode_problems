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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int>st;
        map<int,TreeNode*>mp;
        TreeNode* root;
        for(auto it:descriptions){
            int parent=it[0];
            int child=it[1];
            int isleft=it[2];
            // st.insert(child);
            // st.insert(parent)
            if(mp.find(parent)==mp.end()){

            mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
               mp[child]=new TreeNode(child); 
            }
            st.insert(child);
        if(isleft==1){
            mp[parent]->left=mp[child];
        }
        else{
            mp[parent]->right=mp[child];
        }
        }
    for(auto it:mp){
        if(st.find(it.first)==st.end()){
            return mp[it.first];
        }
    }
        return root;
    }
};