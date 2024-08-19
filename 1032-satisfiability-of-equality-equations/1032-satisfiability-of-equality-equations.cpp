class dsu {
public:
    vector<int> parent;
    vector<int> rank;
    dsu(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find_parent(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = find_parent(parent[u]);
    }
    void union_by_rank(int u, int v) {
        int par_u = find_parent(u);
        int par_v = find_parent(v);
        if (par_u == par_v) {
            return;
        }
        if (rank[par_u] < rank[par_v]) {
            parent[par_u] = par_v;
        } else if (rank[par_u] > rank[par_v]) {
            parent[par_v] = par_u;
        } else {
            parent[par_u] = par_v;
            rank[par_v]++;
        }
    }
};

class Solution {
public:
    string chartostr(char a) {
        string s = "";
        s += a;
        return s;
    }
    bool equationsPossible(vector<string>& equations) {

        map<char, int> mp;

        for (auto it : equations) {
            mp[it[0]]++;
            mp[it[3]]++;
        }
        int n = mp.size();
        dsu ds(26);
        for (auto it : equations) {
            // string a = chartostr(it[0]);
            // string b = chartostr(it[3]);
            if (it[1] == '=') {
                ds.union_by_rank(it[0]-'a', it[3]-'a');
            }
        }
        for (auto it : equations) {
            // string a = chartostr(it[0]);
            // string b = chartostr(it[3]);
            if (it[1] == '!') {
                if (ds.find_parent(it[0]-'a') == ds.find_parent(it[3]-'a')) {
                    return false;
                }
            }
        }
        return true;
    }
};