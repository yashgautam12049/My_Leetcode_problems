class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        map<int,vector<int>>mp;
        int n=routes.size();
        // stops  index
        for(int i=0;i<n;i++){
            for(int j=0;j<routes[i].size();j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        vector<int>vis(n,0);
        queue<int>q;
        for(auto it:mp[source]){
            q.push(it);
            vis[it]=1;
        }
        int bus=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int next=q.front();
                q.pop();
                for(auto it:routes[next]){
                    if(it==target){
                        return bus;
                    }
                    for(auto i:mp[it]){
                        if(vis[i]==0){
                            vis[i]=1;
                            q.push(i);
                        }
                    }
                }

            }
            bus++;
        }
        return -1;
    }
};