class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int ans;
        if(tokens.size()==1){
            return stoi(tokens[0]);
        }
        for(auto it:tokens){
            if(it=="+"){
                int a,b;
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                ans=a+b;
                st.push(ans);
            }
            else if(it=="-"){
                int a,b;
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                ans=a-b;
                st.push(ans);
            }
            else if(it=="*"){
                int a,b;
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                ans=a*b;
                st.push(ans);
            }
            else if(it=="/"){
                int a,b;
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
                ans=a/b;
                st.push(ans);
            }
            else{
                string a=it;
                st.push(stoi(a));
            }
        }
        return ans;
    }
};