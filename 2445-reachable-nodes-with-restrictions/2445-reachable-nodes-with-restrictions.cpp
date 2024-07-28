class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        set<int>st(restricted.begin(),restricted.end());
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        //bfs 
        queue<int>q;
        q.push(0);
        vis[0]=1;
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
            int ngbr=q.front();
            q.pop();
            vis[ngbr]=1;
            for(auto it:adj[ngbr]){
                if(st.find(it)==st.end() && vis[it]==0){
                q.push(it);
                ans++;
                }
            }
            }
        }
        return ans;
    }
};