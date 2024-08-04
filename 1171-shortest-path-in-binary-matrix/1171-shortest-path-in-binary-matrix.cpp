class Solution {
public:
    bool isafe(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < n && i >= 0 && j < m && j >= 0 && grid[i][j] == 0) {
            return 1;
        }
        return 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 0 || grid[0][0] != 0 || grid[n - 1][m - 1] != 0) {
            return -1;
        }
        vector<vector<int>> temp(n, vector<int>(m, INT_MAX));
        // defing direction
        int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
        int dc[] = {-1, 1, 0, 0, -1, 1, -1, 1};
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({1, {0, 0}});
        temp[0][0] = 1;
        while (!pq.empty()) {
            int length = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for (int k = 0; k < 8; k++) {
                int new_x = i + dr[k];
                int new_y = j + dc[k];
                if (isafe(new_x, new_y, grid)) {
                    if (temp[new_x][new_y] > length+1) {
                        temp[new_x][new_y] = length+1;
                        pq.push({length + 1, {new_x, new_y}});
                    }
                }
            }
        }
        if(temp[n - 1][m - 1]==INT_MAX) return -1;
        return temp[n - 1][m - 1];
    }
};