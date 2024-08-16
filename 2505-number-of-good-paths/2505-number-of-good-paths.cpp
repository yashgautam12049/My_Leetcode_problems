class DSU{
    public:
    vector<int>parent;
    // vector<int>size;
    vector<int>rank;
    DSU(int n){
        parent.resize(n);
        // size.resize(n+1,0);
        rank.resize(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    }
    int findparent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findparent(parent[u]);
    }
    // void union_by_union(int u,int v){
    //     if(findparent(u)==findparent(v)){
    //         return;
    //     }
    //     if(size[u]>size[v]){
    //         parent[v]=u;
    //         size[u]+=size[v];
    //     }
    //     else{
    //     size[v]+=size[u];
    //     parent[u]=v;
    //     }
    // }
    void union_by_rank(int u,int v){
        int par_u=findparent(u);
        int par_v=findparent(v);
        if(par_u==par_v){
            return;
        }
        if(rank[par_u]<rank[par_v]){
            parent[par_u]=par_v;
        }
        else if(rank[par_v]<rank[par_u]){
            parent[par_v]=par_u;
        }
        else{
            parent[par_u]=par_v;
            rank[par_v]++;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        DSU ds(n);
        int result=n;
        map<int,vector<int>>val_store;
        map<int,vector<int>>adj;
        vector<bool>is_active(n,false);
        for(int i=0;i<n;i++){
            val_store[vals[i]].push_back(i);
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(auto it:val_store){
            //node of val
            for(auto j:it.second){
                for(auto k:adj[j]){
                    if(is_active[k]){
                        ds.union_by_rank(j,k);
                    }
                }
                is_active[j]=true;
            }
        
            vector<int>inke_parent;
            for(auto j:it.second){
                int paren=ds.findparent(j);
                inke_parent.push_back(paren);
            }
            sort(inke_parent.begin(),inke_parent.end());
            for(int i=0;i<inke_parent.size();i++){
                int count=0;
                int curr=inke_parent[i];
                while(i<inke_parent.size() && curr==inke_parent[i]){
                    i++;
                    count++;
                }
                i--;
                int temp=count*(count-1);
                    result+=(temp/2);
            }
            // map<int,int>common_parent;
            // for(auto it:inke_parent){
            //     common_parent[it]++;
            // }
            // for(auto it:common_parent){
            //     int total=it.second;
            //         int temp=total*(total-1);
            //         result+=(temp/2);
            // }
        }
        return result;
    }
};