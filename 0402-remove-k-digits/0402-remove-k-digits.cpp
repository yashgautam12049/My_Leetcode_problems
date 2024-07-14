class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(n<=k) return "0";
        stack<char>st;
        st.push(num[0]);
        for(int i=1;i<n;i++){
            while(!st.empty()&& st.top()>num[i] && k>0 ){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        int i=ans.size()-1;
        while(i>=0){
            if(ans[i]=='0'){
                i--;
            }
            else break;
        }
        // if(i==)
        ans.erase(ans.begin()+i+1,ans.end());
        reverse(ans.begin(),ans.end());
        return ans.empty()?"0":ans;
    }
};