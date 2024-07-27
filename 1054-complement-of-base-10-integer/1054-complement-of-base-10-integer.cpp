class Solution {
public:
string ans="";
    string getstring(char x){
        string s(1,x);
        return s;
    }
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        while(n!=0){
           int rem=n%2;
        ans+=to_string(rem);
        n=n/2;
    //   if(n==0) return;
        // bit(n/2);   
        }
        // bit(n);
        reverse(ans.begin(),ans.end());
        //complement
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='0') ans[i]='1';
            else{
                ans[i]='0';
            }
        }
        int k=0;
        int result=0;
        for(int i=ans.size()-1;i>=0;i--){
            string a=getstring(ans[i]);
            result+=(stoi(a)*(1<<k));
            k++;
        }
        return result;
    }
};