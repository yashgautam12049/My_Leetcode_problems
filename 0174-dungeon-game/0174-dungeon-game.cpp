class Solution {
public:
int dp[201][201];
    int solve(int i,int j,vector<vector<int>>& dungeon){
        //up
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(i<0 || i>=n || j<0 || j>=m){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int health= min(solve(i+1,j,dungeon),solve(i,j+1,dungeon));
        //left;
        if(health==INT_MAX){
            health=1;
        }
        if((health-dungeon[i][j])>0){
            health=health-dungeon[i][j];
        }
        else{
            health=1;
        }
        return dp[i][j]=health;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,dungeon);
    }
};