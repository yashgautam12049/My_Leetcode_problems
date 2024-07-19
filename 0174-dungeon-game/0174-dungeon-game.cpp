class Solution {
public:
    int dp[201][201];
    int solve(int r,int c,vector<vector<int>>& dungeon){
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(r<0 || r>=n || c<0 || c>=m) return INT_MAX;
        
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int a=min(solve(r,c+1,dungeon),solve(r+1,c,dungeon));
        if(a==INT_MAX){
            a=1;
        }
        int res=0;
        if(a-dungeon[r][c]>0){
            res=a-dungeon[r][c];
        }
        else{
            res=1;
        }
 
        return dp[r][c]=res;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,dungeon);
    }
};