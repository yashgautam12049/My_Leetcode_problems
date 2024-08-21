class Solution {
public:
int dp[101][2][101];
    int solveforalice(int ind,vector<int>& piles,bool person,int m){
        
        int n=piles.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind][person][m]!=-1){
            return dp[ind][person][m];
        }
        int stone=0;
        int comparasion=(person==1)?-1:INT_MAX;
        for(int i=1;i<=min(2*m,n-ind);i++){
            stone+=piles[ind+i-1];//bcz of prefix sum
        if(person==1){
            comparasion=max(comparasion,stone+solveforalice(ind+i,piles,0,max(m,i)));
        }
        else{
            comparasion=min(comparasion,solveforalice(ind+i,piles,1,max(m,i)));
        }
        }
        return dp[ind][person][m]=comparasion;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solveforalice(0,piles,1,1);
    }
};