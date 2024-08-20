class dsu{
    public:
    vector<int>parent;
    vector<int>rank;
    dsu(int n){
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
        return parent[u]=find_par(parent[u]);
    }
    void join_by_rank(int u,int v){
        int par_u=find_par(u);
        int par_v=find_par(v);
        if(par_u==par_v){
            return;
        }
        if(rank[par_u]>rank[par_v]){
            parent[par_v]=par_u;
        }
        else if(rank[par_v]>rank[par_u]){
            parent[par_u]=par_v;
        }
        else{
            parent[par_v]=par_u;
            rank[par_u]++;
        }
    }
};
class Solution {
public:
    bool similar(string s1,string s2){
        int ans=0;
        if(s1.size()!=s2.size()){
            return 0;
        }
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                ans++;
            }
        }
        if(ans>=3){
            return 0;
        }
        return 1;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int result=n;
        dsu ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i],strs[j]) && ds.find_par(i)!=ds.find_par(j)){
                    ds.join_by_rank(i,j);
                    result--;
                }
            }
        }
        return result;
    }
};