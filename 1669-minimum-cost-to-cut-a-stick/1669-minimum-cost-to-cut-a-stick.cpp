#define pb push_back
using ll=long long;
class Solution {
public:
ll dp[102][102];
ll cost;
    ll solve(vector<int>& cuts,ll l,ll r){
        if(r-l<2)return 0;
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        ll result=INT_MAX;
        for(ll i=l+1;i<=r-1;i++){
            cost=(cuts[r]-cuts[l])+solve(cuts,l,i)+solve(cuts,i,r);
            result=min(result,cost);
        }
        return dp[l][r]=result;
    }
    ll minCost(ll n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.pb(0);
        cuts.pb(n);
        sort(cuts.begin(),cuts.end());
        return solve(cuts,0,cuts.size()-1);
    }
};