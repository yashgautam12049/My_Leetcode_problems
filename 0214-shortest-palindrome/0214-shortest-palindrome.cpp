class Solution {
public:
    void longestcommonpalidrome(string s,vector<int>&lps){
        int n=s.size();
        lps[0]=0;
        int i=1;
        int length=0;
        while(i<n){
            if(s[i]==s[length]){
                length++;
                lps[i]=length;
                i++;
            }
            else{
                if(length!=0){
                    length=lps[length-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        string m=s+'#'+t;
        vector<int>lps(m.size());
        longestcommonpalidrome(m,lps);
        int i=lps[m.size()-1];
        string a=s.substr(i);
        reverse(a.begin(),a.end());
        return a+s;
    }
};