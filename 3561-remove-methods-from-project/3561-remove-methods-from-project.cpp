class Solution {
public:

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //invoked by nodes
        map<int,vector<int>>invoked;
        for(auto it:invocations){
            invoked[it[0]].push_back(it[1]);
        }
        //normal dfs
        vector<int>vis(n,0);
        auto dfs=[&](auto &&dfs, int u){
            if(vis[u]) return;
            vis[u]=1;
            for(auto it:invoked[u]){
                dfs(dfs,it);
            }
        };
        dfs(dfs,k);
        bool all=false;
        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            if(vis[v]==1 && !vis[u]){
                all=true;
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            if(all || !vis[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};