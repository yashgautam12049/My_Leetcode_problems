bool myCompare(int X, int Y) { return (to_string(X) + to_string(Y)) > (to_string(Y) + to_string(X)); }
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<int> s = nums;

        sort(s.begin(), s.end(), myCompare);
        string ans = "";
        for (auto it : s) {
            ans += to_string(it);
        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
    }
};