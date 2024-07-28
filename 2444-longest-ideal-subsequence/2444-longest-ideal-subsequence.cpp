class Solution {
public:
    // int dp[100001][100001];
    // int solve(int ind,string s, int k,int prev){
    //     //take
    //     if(ind==s.size()) return 0;
    //     if(dp[ind][prev] !=-1){
    //         return dp[ind][prev];
    //     }
    //     int take=0;
    //     if(abs((s[ind]-'a')-(s[prev]-'a'))<=k){
    //         take=1+solve(ind+1,s,k,ind);
    //     }
    //     //not take
    //     int not_take=solve(ind+1,s,k,prev);
    //     return dp[ind][prev] = max(take,not_take);
    //     // return max(take,not_take);
    // }
    int longestIdealString(string s, int k) {
        // memset(dp,-1,sizeof(dp));
        int n=s.size();
        vector<int>dp(26,0);

        int result=0;
        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';
            int left=max(0,(curr)-k);
            int right=min(25,(curr)+k);

            int longest=0;
            for(int j=right;j>=left;j--){
                longest=max(longest,dp[j]);
            }
                dp[curr]=max(dp[curr],longest+1);
            result=max(result,dp[curr]);
        }
        return result;
    }
};