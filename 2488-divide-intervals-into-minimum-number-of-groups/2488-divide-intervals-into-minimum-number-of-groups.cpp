// class DSU{
//     public:
//     vector<int>parent;
//     vector<int>rank;
//     DSU(int n){
//         parent.resize(n);
//         rank.resize(n);
//         for(int i=0;i<n;i++){
//             parent[i]=i;
//         }
//     }
//     int find_par(int u){
//         if(parent[u]==u){
//             return u;
//         }
//         return find_par(parent[u]);
//     }
//     void union_by_rank(int u,int v){
//         int u_par=find_par(u);
//         int v_par=find_par(v);
//         if(u_par==v_par){
//             return;
//         }
//         if(rank[u_par]>rank[v_par]){
//             parent[v]=u;
//         }
//         else if(rank[v_par]>rank[u_par]){
//             parent[u]=v;
//         }
//         else{
//             parent[v]=u;
//             rank[u]++;
//         }

//     }
// };
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it:intervals){
            int start=it[0];
            int end=it[1];
            if(!pq.empty() && start>pq.top()){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};