class Solution {
public:
long long universal=0;
    bool check(map<long long,long long>mp,long long t,vector<int>& skill){
        for(int i=0;i<skill.size();i++){
            if(t-skill[i]<0){
                return 0;
            }
            if(mp[t-skill[i]]>0){
                mp[t-skill[i]]--;
            }else{
                return 0;
            }
        }
        return 1;
    }
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        long long low=skill[0];
        long long high=skill[n-1]+low;
        map<long long,long long>mp;
        map<long long,long long>mp1;
        for(long long i=0;i<skill.size();i++){
            mp[skill[i]]++;
        }
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(mp, mid, skill)) {
                universal = mid; 
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        if(universal==0){
            return -1;
        }
        for(long long i=0;i<skill.size();i++){
                mp1[skill[i]]=(universal-skill[i]);
        }
        long long ans=0;
        for(auto it:mp1){
            ans+=(it.first*it.second*mp[it.first]);
        }
        return ans/2;
    }
};