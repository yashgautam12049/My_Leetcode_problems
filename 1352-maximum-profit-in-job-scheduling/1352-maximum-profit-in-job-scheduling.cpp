class Solution {
public:
int dp[50001];
    int getindex(int ind,vector<vector<int>>&store,int idy){
        int low=ind;
        int high=store.size()-1;
        int result=store.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(store[mid][0]>=idy){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
    int solve(int ind,vector<vector<int>>&store){
        int n=store.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        //take 
        int next=getindex(ind+1,store,store[ind][1]);
        int take=store[ind][2]+solve(next,store);
        int not_take=solve(ind+1,store);
        return dp[ind]= max(take,not_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>store;
        int n=startTime.size();
        for(int i=0;i<n;i++){
            vector<int>v;
            v.push_back(startTime[i]);
            v.push_back(endTime[i]);
            v.push_back(profit[i]);
            store.push_back(v);
        }
        sort(store.begin(),store.end());
        return solve(0,store);
    }
};