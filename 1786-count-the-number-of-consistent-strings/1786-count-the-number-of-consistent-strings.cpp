class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char,int>mp;
        int ans=0;
        int n=words.size();
        for(auto it:allowed){
            mp[it]=1;
        }
        for(auto it:words){
            for(auto i:it){
                if(mp.find(i)==mp.end()){
                    ans++;
                    break;
                }
            }
        }
        return n-ans;
    }
};