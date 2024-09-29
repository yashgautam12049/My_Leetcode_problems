class Solution {
public:
    struct number_trie{
        number_trie* left;
        number_trie* right;
    };
    number_trie* getnewnode(){
        number_trie* root=new number_trie();
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    void insert(int num,number_trie* root){
        number_trie* temp=root;
        for(int i=31;i>=0;i--){
            int a=(num>>i)&1;
            if(a==0){
                if(temp->left==NULL){
                    temp->left=getnewnode();
                }
                // temp->left=a;
                temp=temp->left;
            }
            else{
                if(temp->right==NULL){
                    temp->right=getnewnode();
                }
                // temp->right=a;
                temp=temp->right;
            }
        }
    }
    int findmax(int num,number_trie*root){
        number_trie* temp=root;
        int maxor=0;
        for(int i=31;i>=0;i--){
            int ithbit=(num>>i)&1;
            if(ithbit==1){
                if(temp->left!=NULL){
                    maxor+=(pow(2,i));
                    temp=temp->left;
                }else{
                    temp=temp->right;
                }
            }else{
                if(temp->right!=NULL){
                    maxor+=(pow(2,i));
                    temp=temp->right;
                }else{
                    temp=temp->left;
                }
            }
        }
        return maxor;
    }
    int findMaximumXOR(vector<int>& nums) {
        number_trie*root=getnewnode();
        for(auto it:nums){
            insert(it,root);
        }
        int ans=0;
        for(auto it:nums){
            int p=findmax(it,root);
            ans=max(ans,p);
        }
        return ans;
    }
};