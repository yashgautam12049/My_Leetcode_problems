class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(st.size()>0 && st.top()=='(' && s[i]==')'){
                st.pop();
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                ans++;
            }
        }
        return ans+st.size();
    }
};