class Solution {
public:
    bool check(vector<int>& ans,int extra_val) {
        int n=ans.size();
        for (int i = 0; i < n && extra_val!=0; i++) {
            if (ans[i] < 6) {
                ans[i]++;
                extra_val--;
            }
        }
        if(extra_val!=0){
            return false;
        }
        return 1;
    }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans(n);
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int rest_amount = (mean * (n + m)) - sum;
        int each_element = rest_amount / n;
        if (each_element > 6 || each_element <= 0) {
            return {};
        }

        for (int i = 0; i < ((rest_amount % n != 0) ? n - 1 : n); i++) {
            ans[i] = each_element;
        }

        if (rest_amount % n != 0) {
            ans[n - 1] = rest_amount / n + rest_amount % n;
            if (ans[n - 1] > 6) {
                int extra_val = ans[n - 1] - each_element;
                if(check(ans,extra_val)){
                    ans[n-1]=each_element;
                }
                else{
                    return {};
                }
            } 
        }
        return ans;
    }
};