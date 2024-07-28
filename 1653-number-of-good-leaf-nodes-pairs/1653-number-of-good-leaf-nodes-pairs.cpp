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
    void make_undirected(TreeNode* root, TreeNode* prev,
                         map<TreeNode*, vector<TreeNode*>>& mp,
                         unordered_set<TreeNode*>& st) {
        if (!root)
            return;
        if (root->left == NULL && root->right == NULL) {
            st.insert(root);
        }
        if(prev!=NULL){
        mp[root].push_back(prev);
        mp[prev].push_back(root);
        }
        make_undirected(root->left, root, mp, st);
        make_undirected(root->right, root, mp, st);
    }
    int countPairs(TreeNode* root, int distance) {
        // tranform into undirected graph
        map<TreeNode*, vector<TreeNode*>> mp;
        unordered_set<TreeNode*> st;
        make_undirected(root, NULL, mp, st);

        int cnt = 0;
        for (auto it : st) {
            queue<TreeNode*> q;
            unordered_set<TreeNode*>s;
            s.insert(it);
            q.push(it);
            for (int level = 0; level <= distance; level++) {
            int size = q.size();
                while (size--) {
                    TreeNode* curr = q.front();
                    q.pop();
                    if(it!=curr && st.count(curr)){
                        cnt++;
                    }
                
                for(auto ngbr:mp[curr]){
                    if(!s.count(ngbr)){
                    q.push(ngbr);
                    s.insert(ngbr);
                    }
                }
                }
            }
        }
        return cnt/2;
    }
};