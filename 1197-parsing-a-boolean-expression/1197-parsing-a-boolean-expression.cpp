class Solution {
public:
char func(char a,vector<char>temp){
    if(a=='&'){
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='f'){
                return 'f';
            }
        }
                return 't';
    }
    if(a=='|'){
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='t'){
                return 't';
            }
        }
                return 'f';
    }
    if(a=='!'){
        
            if(temp[0]=='t'){
                return 'f';
            }else{
                return 't';
            }
    }
    return 'a';
    
}
    bool parseBoolExpr(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='|' || s[i]=='&' || s[i]=='!' ||s[i]=='(' ||s[i]=='f' || s[i]=='t'){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                vector<char>temp;
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                st.push(func(op,temp));
            }
        }
        return st.top()=='t';
    }
};