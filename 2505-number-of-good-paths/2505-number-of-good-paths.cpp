class DSU {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1); // Initialize size to 1
        rank.resize(n, 1); // Initialize rank to 1
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findparent(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findparent(parent[u]); // Path compression
    }

    void union_by_size(int u, int v) {
        int root_u = findparent(u);
        int root_v = findparent(v);
        if (root_u == root_v) {
            return;
        }
        if (size[root_u] > size[root_v]) {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        } else {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }
    }

    void union_by_rank(int u, int v) {
        int root_u = findparent(u);
        int root_v = findparent(v);
        if (root_u == root_v) {
            return;
        }
        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        DSU ds(n);
        int result = n; // Start with each node being its own "good path"
        map<int, vector<int>> val_store;
        vector<vector<int>> adj(n);

        // Grouping nodes by their values
        for (int i = 0; i < n; i++) {
            val_store[vals[i]].push_back(i);
        }

        // Building the adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Process each value group in increasing order
        for (auto& [val, nodes] : val_store) {
            for (int u : nodes) {
                for (int v : adj[u]) {
                    if (vals[u] >= vals[v]) {
                        ds.union_by_rank(u, v);
                    }
                }
            }

            map<int, int> freq;
            for (int u : nodes) {
                int root = ds.findparent(u);
                freq[root]++;
            }

            for (auto& [root, count] : freq) {
                result += count * (count - 1) / 2;
            }
        }

        return result;
    }
};
