class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                if(ans>0) ans = ans - 1;
            }
            else if (logs[i] == "./") {
                ans = ans;
            } else {
                ans = ans + 1;
            }
        }
        return ans<0?0:ans;
    }
};