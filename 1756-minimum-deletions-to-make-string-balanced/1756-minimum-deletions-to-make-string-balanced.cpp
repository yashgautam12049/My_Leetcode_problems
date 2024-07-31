class Solution {
public:
    // int dp[100001][10000];
    // int solve(int ind,string &s,int prev,vector<vector<int>>&dp){
    //     //take
    //     if(ind==s.size()) return 0;
    //     if(dp[ind][prev+1]!=-1){
    //         return dp[ind][prev+1];
    //     }
    //     int take=0;
    //     if(prev==-1|| (s[ind]=='a' && s[prev]!='b') ||s[ind]=='b'){
    //     take=1+solve(ind+1,s,ind,dp);
    //     }
    //     //not_take
    //     int not_take=solve(ind+1,s,prev,dp);
    //     return dp[ind][prev+1]=max(take,not_take);
    // }
    int minimumDeletions(string s) {
        int n=s.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // memset(dp,-1,sizeof(dp));
        stack<char>st;
        int cnt=0;
        for(auto it:s){
            if(!st.empty() && st.top()=='b' && it=='a'){
                st.pop();
                cnt++;
            }
            else{
                st.push(it);
            }
        }
        return cnt;
    }
};