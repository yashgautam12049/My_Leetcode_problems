class Solution {
public:
    int minLength(string s) {
        int n = s.size();
        stack<char> st;

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }else{
                // not empty
                char ch = st.top();
                if((s[i] == 'B' && ch=='A') || (s[i] == 'D' && ch=='C')){
                    st.pop();
                }else{
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }
};