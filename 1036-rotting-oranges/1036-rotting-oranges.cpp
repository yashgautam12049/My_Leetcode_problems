class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // P;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            vis[x][y]=true;
            q.pop();
            ans=max(ans,t);
            for(auto it:dir){
                int i_x=x+it.first;
                int i_y=y+it.second;
                if(i_x<0 || i_x>=n || i_y<0 || i_y>=m){
                    continue;
                }
                if(grid[i_x][i_y]==0){
                    continue;
                }
                if(grid[i_x][i_y]==1 && vis[i_x][i_y]==false){
                    grid[i_x][i_y]=2;
                    q.push({{i_x,i_y},t+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};