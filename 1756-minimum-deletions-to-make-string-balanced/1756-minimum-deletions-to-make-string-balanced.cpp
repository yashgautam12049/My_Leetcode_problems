class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int countb = 0;
        int counta = 0;
        vector<int> count_b(n, 0);
        vector<int> count_a(n, 0);
        for (int i = 0; i < n; i++) {
            count_b[i] = countb;
            if (s[i] == 'b') {
                countb++;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            count_a[i] = counta;
            if (s[i] == 'a') {
                counta++;
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, count_a[i] + count_b[i]);
        }
        return ans;
    }
};