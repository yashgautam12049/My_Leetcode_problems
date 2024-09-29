class Trie {
public:
    struct trie{
        bool endofword;
        string word;
        trie* children[26];
    };
    trie* getnewnode(){
        trie *root=new trie();
        root->endofword=false;
        root->word="";
        for(int i=0;i<26;i++){
        root->children[i]=NULL;
        }
        return root;
    }
    trie* root;
    Trie() {
        root=getnewnode();
    }
    
    void insert(string word) {
        trie* traverse=root;
        for(char it:word){
            if(traverse->children[it-'a']==NULL){
                traverse->children[it-'a']=getnewnode();
            }
            traverse=traverse->children[it-'a'];
        }
            traverse->endofword=true;
    }
    
    bool search(string word) {
        trie* traverse=root;
        for(char it:word){
            if(traverse->children[it-'a']==NULL){
                return 0;
            }
            traverse=traverse->children[it-'a'];
        }
           if( traverse->endofword==true){
            return 1;
           }
           return 0;
    }
    
    bool startsWith(string prefix) {
        trie* traverse=root;
        for(char it:prefix){
            if(traverse->children[it-'a']==NULL){
                return 0;
            }
            traverse=traverse->children[it-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */