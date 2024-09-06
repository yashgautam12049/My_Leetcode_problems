class DSU{
    public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find_par(int u){
        if(u==parent[u]){
            return u;
        }
        return find_par(parent[u]);
    }
    void union_by_rank(int u,int v){
        int u_par=find_par(u);
        int v_par=find_par(v);
        if(u_par==v_par){
            return;
        }
        if(rank[u_par]>rank[v_par]){
            parent[v_par]=u_par;
        }
        else if(rank[v_par]>rank[u_par]){
            parent[u_par]=v_par;
        }
        else{
            parent[v_par]=u_par;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int row=stones.size();
        DSU ds(row);
        for(int i=0;i<row;i++){
            for(int j=i+1;j<row;j++){
                int r=stones[i][0];
                int c=stones[i][1];
                int r_j=stones[j][0];
                int c_j=stones[j][1];
                if(r==r_j || c==c_j){
                    if(ds.find_par(i)!=ds.find_par(j)){
                    ds.union_by_rank(i,j);
                    }
                }
            }
        }
        int group=0;
        for(int i=0;i<row;i++){
            if(ds.find_par(i)==i){
                group++;
            }
        }
        return row-group;
    }
};