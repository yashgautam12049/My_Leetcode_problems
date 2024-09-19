class Solution {
public:

   vector<int>solve(string s){
    int n=s.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
            continue;
            }
            else{
                vector<int> left=diffWaysToCompute(s.substr(0,i));
                vector<int> right=diffWaysToCompute(s.substr(i+1));
                for(auto it:left){
                    for(auto j:right){
                        if(s[i]=='+'){
                            ans.push_back((it)+(j));
                        }
                        if(s[i]=='-'){
                            ans.push_back((it)-(j));
                        }
                        if(s[i]=='*'){
                            ans.push_back((it)*(j));
                        }
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(s));
        }
        return ans;
   }
    vector<int> diffWaysToCompute(string s) {
        //add brackets
        return solve(s);
    }
};