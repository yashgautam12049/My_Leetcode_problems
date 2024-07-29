class Solution {
public:
long long dp[1003][1003][3];
long long dp1[1003][1003][3];
    int solve(int ind,vector<int>&rating,int prev,int size){
        if(size==3){
            return 1;
        } 
        if(ind==rating.size()) return 0;
        if(dp[ind][prev+1][size]!=-1){
            return dp[ind][prev+1][size];
        }
        int take=0;
        if(prev==-1|| rating[ind]>rating[prev]){
        take=solve(ind+1,rating,ind,size+1);
        }
        //not_take
        int not_take =solve(ind+1,rating,prev,size);
        return dp[ind][prev+1][size]=(take+not_take);
    }
    int small(int ind,vector<int>&rating,int prev,int size){
        if(size==3){
            return 1;
        } 
        if(ind==rating.size()) return 0;
        if(dp1[ind][prev+1][size]!=-1){
            return dp1[ind][prev+1][size];
        }
        int take=0;
        if(prev==-1|| rating[ind]<rating[prev]){
        take=small(ind+1,rating,ind,size+1);
        }
        //not_take
        int not_take=small(ind+1,rating,prev,size);
        return dp1[ind][prev+1][size]=(take+not_take);
    }
    int numTeams(vector<int>& rating) {
        //greater
        // vector<int>ans;
        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));
        int greater=solve(0,rating,-1,0);
        //smaller
        int smaller=small(0,rating,-1,0);
        return greater+smaller;
    }
};