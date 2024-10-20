class Solution {
public:
    vector<string>ans;
    bool isvalid(string s){
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }
            else{
                
                if(st.empty()){
                    return 0;
                }
                st.pop();
            }
        }
        if(st.empty())return 1;
        return 0;
    }
    void solve(string &s,int n){
        if(s.size()==2*n){
            if(isvalid(s)){
                ans.push_back(s);
            }
            return;
        }
        s.push_back('(');
        solve(s,n);
        s.pop_back();
        s.push_back(')');
        solve(s,n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        solve(s,n);
        return ans;
    }
};