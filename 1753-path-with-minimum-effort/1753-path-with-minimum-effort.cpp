class Solution {
public:
    bool isafe(int i, int j, vector<vector<int>>& heights) {
        // base condition
        int n = heights.size();
        int m = heights[0].size();
        if (i < n && i >= 0 && j < m && j >= 0) {
            return 1;
        }
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        // dijkstra
        int n = heights.size();
        int m = heights[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vector<vector<int>> grid(n, vector<int>(m, INT_MAX));
            priority_queue<pair<int, pair<int, int>>,
                           vector<pair<int, pair<int, int>>>,
                           greater<pair<int, pair<int, int>>>>
                pq;
        pq.push({0, {0, 0}}); // diff,i,j
        grid[0][0] = 0;
        while (!pq.empty()) {
            int diff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for (int k = 0; k < 4; k++) {
                int x_row = i + dr[k];
                int y_col = j + dc[k];
                if (isafe(x_row, y_col,heights)) {
                    int abs_diff = abs(heights[i][j] - heights[x_row][y_col]);
                    int maxdiff = max(diff, abs_diff);
                    if (maxdiff < grid[x_row][y_col]) {
                        grid[x_row][y_col] = maxdiff;
                        pq.push({maxdiff, {x_row, y_col}});
                    }
                }
            }
        }
        return grid[n - 1][m - 1];
    }
};