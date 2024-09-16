class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int>store(5,0);
        map<string,int>mp;
        int ans=0;
        string curr="00000";
        mp[curr]=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                store[0]=(store[0]+1)%2;
            }
            if(s[i]=='e'){
                store[1]=(store[1]+1)%2;
            }
            if(s[i]=='i'){
                store[2]=(store[2]+1)%2;
            }
            if(s[i]=='o'){
                store[3]=(store[3]+1)%2;
            }
            if(s[i]=='u'){
                store[4]=(store[4]+1)%2;
            }
            curr="";
            for(int j=0;j<5;j++){
                curr+=to_string(store[j]);
            }
            if(mp.find(curr)!=mp.end()){
            ans=max(ans,i-mp[curr]);
            }else{
            mp[curr]=i;
            }
        }
        return ans;
    }
};