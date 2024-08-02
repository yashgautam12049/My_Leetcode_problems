class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dijkstra code
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>result(n+1,INT_MAX);
        map<int,vector<pair<int,int>>>adj;
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        result[k]=0;
        pq.push({k,0}); // node,weight
        while(!pq.empty()){
            int v=pq.top().first;
            int wt=pq.top().second;
            pq.pop();
            for(auto it:adj[v]){
                int go=it.first;
                int wei=it.second;
                if(wei+wt<result[go]){
                    result[go]=wei+result[v];
                    pq.push({go,wei+wt});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,result[i]);
        }
        
        return ans==INT_MAX?-1:ans;
    }
};