class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<bool>>&vis,vector<vector<bool>>&vis1){
        // row constant
        int n=matrix.size();
        int m=matrix[0].size();
        for(int k=0;k<m;k++){
            // if(vis1[i][k]==1 && vis[i][k]==1) break;
            matrix[i][k]=0;
            vis1[i][k]=true;
        }
        // col constant
        for(int k=0;k<n;k++){
            // if(vis1[k][j]==1 && vis[k][j]==1) break;
            matrix[k][j]=0;
            vis1[k][j]=true;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<bool>>vis1(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    vis[i][j]=true;
                    // dfs(i,j,matrix,vis);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0 && vis[i][j]==true){
                    // vis[i][j]=true;
                    dfs(i,j,matrix,vis,vis1);
                }
            }
        }
    }
};