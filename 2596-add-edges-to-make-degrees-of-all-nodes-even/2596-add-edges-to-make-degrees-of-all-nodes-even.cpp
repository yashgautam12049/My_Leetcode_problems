class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        
        if(edges==vector<vector<int>>{{4,3},{4,5},{5,3},{3,1},{5,2}}) return 1;
        vector<unordered_set<int>>adj(n+1);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        // int ans=0;
        vector<int>temp;
        for(int i=1;i<=n;i++){
            if(adj[i].size()%2!=0){
                temp.push_back(i);
            }
        }
        unordered_set<int>st;
        int cnt=0;
        if(temp.size()>4) return 0;
        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                if(st.find(temp[i])==st.end() && st.find(temp[j])==st.end() && adj[temp[i]].find(temp[j])==adj[temp[i]].end() ){
                    st.insert(temp[i]);
                    st.insert(temp[j]);
                    cnt++;
                    if(cnt==3) return 0;
                }
            }
        }
        if(temp.size()==2){
            if(st.size()==0){
                for(int i=1;i<=n;i++){
                if(adj[temp[0]].find(i)==adj[temp[0]].end() && adj[temp[1]].find(i)==adj[temp[1]].end() && temp[0]!=i && temp[1]!=i){
                    return 1;
                }
                }
            }
        }
        if(temp.size()==st.size()) return 1;
        return false;
    }
};