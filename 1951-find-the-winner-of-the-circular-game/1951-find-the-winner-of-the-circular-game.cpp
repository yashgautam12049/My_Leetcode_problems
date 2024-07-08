#include <vector>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> dp(n + 1, true);  // Initialize the vector with true
        int i = 1;
        int t = 0;
        while (t < n - 1) {
            int m = k;
            while (m > 0) {
                if (dp[i] == true) {
                    m--;
                }
                if (m == 0) {
                    dp[i] = false;
                    t++;
                }
                i++;
                if (i > n) {
                    i = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dp[i] == true) {
                return i;
            }
        }
        return 0;
    }
};
