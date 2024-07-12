class Solution {
public:
//  bool a,b,c,d;
    bool dfs(vector<vector<int>>& grid,int mid,int i,int j,vector<vector<bool>>&vis){
        bool check;
        int n=grid.size();
        if(i>=n || i<0 || j>=n || j<0 || grid[i][j]>mid || vis[i][j]==true) return 0;
        if(i==n-1 && j==n-1 && grid[i][j]<=mid) return 1;
        vis[i][j]=true;
        // if(i<n && i>=0 && j<n && j>=0 && grid[i][j]<=mid && vis[i][j]==false){
        bool a=dfs(grid,mid,i+1,j,vis);
        bool b=dfs(grid,mid,i,j+1,vis);
        bool c=dfs(grid,mid,i-1,j,vis);
        bool d=dfs(grid,mid,i,j-1,vis);
        check=a||b||c||d;
        // }
        return check;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        int low=grid[0][0];
        int high=n*n;
        while(low<=high){
            int mid=low+(high-low)/2;
            vector<vector<bool>>vis(n,vector<bool>(n,false));
            if(dfs(grid,mid,0,0,vis)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        // queue<pair<int,int>>q;
        // q.push({0,0});
        // while(!q.empty()){
        //     int next_node=q.front().first;
        //     int time=q.front().second;
        //     q.pop();
        //     int dr[]={-1,0,1,0};
        //     int dc[]={0,-1,0,1};
        //     for(int i=0;i<4;i++){
        //         int new_row=next_node+dr[i];
        //         int new_col=next_node+dc[i];

        //     }
        // }
        return ans;
    }
};