class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<pair<int,int>>>adj;
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>vertex(n+1,INT_MAX);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,src}}); //stops,wt,source
        vertex[src]=0;
        while(!pq.empty()){
            int stop=pq.top().first;
            int v=pq.top().second.second;
            int wt=pq.top().second.first;
            pq.pop();
            if(stop>k) continue;
            
            for(auto it:adj[v]){
                int go=it.first;
                int go_wt=it.second;
                if(go_wt+wt<vertex[go] && stop<=k){
                    vertex[go]=go_wt+wt;
                    pq.push({stop+1,{go_wt+wt,go}});
                }
            }
        }
        if(vertex[dst]==INT_MAX){
                return -1;
            }
        return vertex[dst];
    }
};