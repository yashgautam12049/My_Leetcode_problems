class Solution {
public:
    int minSwaps(string s) {
        stack<int>open_bracket;
        int open;
        for(int i=0;i<s.size();i++){
            if(open_bracket.size()!=0 && s[i]==']'){
                open_bracket.pop();
            }else if(s[i]=='['){
                open_bracket.push(s[i]);
            }
        }
        open=open_bracket.size();
        return (open+1)/2;
    }
};