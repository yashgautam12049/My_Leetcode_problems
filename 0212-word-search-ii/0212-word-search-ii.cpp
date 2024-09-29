class Solution {
public:
vector<string>result;
int row,col;
    //node struct for trie
    struct tries{
        bool endofword;
        string word;
        tries* children[26];
    };

    tries* getnewnode(){
        tries* new_node=new tries();
        new_node->endofword=false;
        
        for(int i=0;i<26;i++){
            new_node->children[i]=NULL;
        }
        new_node->word="";
        return new_node;
    }

    //insert in trie
    void insert(tries *root,string wordss){
        tries* traverse=root;
        for(char st:wordss){
            if(traverse->children[st-'a']==NULL){
                traverse->children[st-'a']=getnewnode();
            }
            traverse=traverse->children[st-'a'];
        }
        traverse->endofword=true;
        traverse->word=wordss;
    }
    void findword(int i,int j,vector<vector<char>>& board,tries* root){
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        if(i<0 || j<0 || i>=row || j>=col||board[i][j]=='$' || root->children[board[i][j]-'a']==NULL){
            return;
        }
        
        root=root->children[board[i][j]-'a'];
        if(root->endofword==true){
            result.push_back(root->word);
            root->endofword=false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        for(pair<int,int> it:dir){
            int new_x=i+it.first;
            int new_y=j+it.second;
            findword(new_x,new_y,board,root);
        }
        board[i][j]=temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row=board.size();
        col=board[0].size();
        //initialize trie
        tries* root=getnewnode();

        //insertion in trie
        for(string it:words){
            insert(root,it);
        }
        //main operation
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                char ch=board[i][j];
                if(root->children[ch-'a']!=NULL){
                    findword(i,j,board,root);
                }
            }
        }
        return result;
    }
};