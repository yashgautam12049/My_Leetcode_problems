class Solution {
public:
    bool ismagic_square(vector<vector<int>>& grid, int i, int j) {
        set<int> check_distinct;
        for (int k = i; k < i + 3; k++) {
            for (int l = j; l < j + 3; l++) {
                if (check_distinct.find(grid[k][l]) != check_distinct.end() ||
                    (grid[k][l] < 1 || grid[k][l] > 9)) {
                    return false;
                } else {
                    check_distinct.insert(grid[k][l]);
                }
            }
        }
        int Rsum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        for (int row = i; row < i + 3; row++) {
            if (grid[row][j] + grid[row][j + 1] + grid[row][j + 2] != Rsum) {
                return false;
            }
        }
        for (int col = j; col < j + 3; col++) {
            if (grid[i][col] + grid[i + 1][col] + grid[i + 2][col] != Rsum) {
                return false;
            }
        }
        if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != Rsum) {
            return false;
        }
        if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != Rsum) {
            return false;
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        // taking 3 on row
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (ismagic_square(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};