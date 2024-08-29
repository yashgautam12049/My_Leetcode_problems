class dsu{
    public:
    vector<int>rank,parent,size;
    dsu(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionbysize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int r=0;
        int c=0;
        for(auto it:stones){
            r=max(r,it[0]);
            c=max(c,it[1]);
        }
        // int r=stones.size();
        // int c=stones[0].size();
        dsu ds(r+c+1);
        map<int,int>mp;
        for(auto it:stones){
            int row=it[0];
            int col=r+it[1]+1;
            ds.unionbyrank(row,col);
            mp[row]=1;
            mp[col]=1;
        }
        int cnt=0;
        for(auto it:mp){
            if(ds.findUpar(it.first)==it.first){
                cnt++;
            }
        }
        return stones.size()-cnt;
    }
};