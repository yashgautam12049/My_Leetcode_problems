class Solution {
public:
int dp[51][51][11];
int mod=1e9+7;
//recursion
int solve(vector<vector<int>>&grid,int i,int j,int k){
    int n=grid.size();
        int m=grid[0].size();
    if(k==1){
        if(grid[i][j]>=1){
        return 1;
        }
        return 0;
    }
    if(grid[i][j]<k){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int ans=0;
    //horizontal
    for(int h=i+1;h<n;h++){
        int lower_part=grid[h][j];
        int upper_part=grid[i][j]-lower_part;
        if(upper_part>0 && lower_part>=k-1){
            ans=(ans%mod+solve(grid,h,j,k-1)%mod)%mod;
        }
    }
    //vertical
    for(int v=j+1;v<m;v++){
        int right_part=grid[i][v];
        int left_part=grid[i][j]-right_part;
        if(left_part>0 && right_part>=k-1){
            ans=(ans%mod+solve(grid,i,v,k-1)%mod)%mod;
        }
    }
    return dp[i][j][k]=ans%mod;
}

//apple_count
    void count_apple(vector<vector<int>>&grid,vector<string>& pizza){
        int n=pizza.size();
        int m=pizza[0].size();
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                grid[i][j]=grid[i][j+1];
                for(int l=i;l<n;l++){
                    if(pizza[l][j]=='A'){
                    grid[i][j]++;
                    }
                }
            }
        }
    }
    int ways(vector<string>& pizza, int k) {
        int n=pizza.size();
        int m=pizza[0].size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>grid(n+1,vector<int>(m+1,0));
        count_apple(grid,pizza);
        return solve(grid,0,0,k);
    }
};