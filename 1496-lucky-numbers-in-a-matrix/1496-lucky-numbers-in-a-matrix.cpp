class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int index;
        int index_r,index_c;
        vector<pair<int, int>> row;
        vector<int> min;
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            int a = INT_MAX;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < a) {
                    a = matrix[i][j];
                    index_r = i;
                    index_c = j;
                }
            }
            min.push_back(a);
            row.push_back({index_r, index_c});
        }
        for (int j = 0; j < min.size(); j++) {
            int b = INT_MIN;
            for (int i = 0; i < n; i++) {
                if (matrix[i][row[j].second] > b) {
                    b = matrix[i][index_c];
                }
            }
            if (b == min[j]) {
                ans.push_back(b);
            }
        }
        return ans;
    }
};