class Solution {
public:
    int dp[51];
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        dp[n]=0;
        set<string> st(dictionary.begin(), dictionary.end());
        for (int i = n-1; i >= 0; i--) {
             dp[i] = 1 + dp[i+1];
            string a = "";
            for (int j = i; j < n; j++) {
                a += s[j];
                if (st.find(a) != st.end()) {
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};