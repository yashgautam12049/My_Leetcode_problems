struct trie {
    trie* children[26];
    int countP;
};

class Solution {
public:
    trie* getnewnode() {
        trie* root = new trie();
        root->countP = 0;
        for (int i = 0; i < 26; i++) {
            root->children[i] = NULL;
        }
        return root;
    }
    void insert(trie* root, string word) {
        trie* crawl = root;
        for (int i = 0; i < word.size(); i++) {
            int ch=word[i]-'a';
            if (crawl->children[ch] == NULL) {
                crawl->children[ch] = getnewnode();
            }
            crawl->children[ch]->countP+=1;
            crawl = crawl->children[ch];
        }
    }
    int score(trie* root, string word){
        int ans=0;
        trie* crawl = root;
        for (int i = 0; i < word.size(); i++) {
            int ch=word[i]-'a';
            ans+=(crawl->children[ch]->countP);
            crawl = crawl->children[ch];
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        trie* temp=getnewnode();
        for(auto it:words){
            insert(temp,it);
        }
        vector<int>ans;
        for(auto it:words){
            ans.push_back(score(temp,it));
        }
        return ans;
    }
};