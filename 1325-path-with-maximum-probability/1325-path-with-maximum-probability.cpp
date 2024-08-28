class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // priority_queue<pair<int,pair<double,int>>,vector<pair<int,pair<double,int>>>,greater<pair<int,pair<double,int>>>>pq;
        priority_queue<pair<double,int>>pq;
        pq.push({1.00,start_node});
        map<int,vector<pair<int,double>>>adj;
        int i=0;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],succProb[i]});
            adj[it[1]].push_back({it[0],succProb[i]});
            i++;
        }
        int V=adj.size();
        vector<double>result(n,0.0);
        result[start_node]=1.0;
        while(!pq.empty()){
            // int dist=pq.top().first;
            double prob=pq.top().first;
            int v=pq.top().second;
            pq.pop();
            if(v==end_node){
                return prob;
            }
            for(auto it:adj[v]){
                if(result[it.first]<prob*it.second){
                    result[it.first]=prob*it.second;
                    pq.push({prob*it.second,it.first});
                }
            }
        }
        return result[end_node];
    }
};