class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph,
             vector<int>& color,int curr_color) {
        int n = graph.size();
        color[i] = curr_color;
            for (auto it : graph[i]) {
                if (color[i] == color[it]) {
                    return 0;
                }
                if(color[it]==-1){
                    curr_color=1-color[i];
                
                    if(dfs(it,graph,color,curr_color)==false){
                        return 0;
                    }
                }
                
            }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (dfs(i, graph, color, 1) == false) {
                    return 0;
                }
            }
        }
        return 1;
    }
};