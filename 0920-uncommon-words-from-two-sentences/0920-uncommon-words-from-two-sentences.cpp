class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word="";
        map<string,int>mp;
        while(ss1>>word){
            mp[word]++;
        }
        while(ss2>>word){
            mp[word]++;
        }
        for(auto it:mp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};