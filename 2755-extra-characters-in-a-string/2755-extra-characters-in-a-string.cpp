class Solution {
public:
int dp[51];
    int solve(int i,string s,set<string>st){
        int n=s.size();
        //base case
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //not take as extra 
        int take=INT_MAX;
        string a="";
        for(int j=i;j<n;j++){
            a+=s[j];
            if(st.find(a)!=st.end()){
                take=min(take,solve(j+1,s,st));
            }
        }
        
        //take as extra
        int take_extra=1+solve(i+1,s,st);
        return dp[i]= min(take,take_extra);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        set<string>st(dictionary.begin(),dictionary.end());
        return solve(0,s,st);
    }
};