using ll=long long;
int mod=1e9+7;
class Solution {
public:
int dp[23][2][2][401];
    ll solve(int ind,bool tight1,bool tight2,string &num1, string &num2,int sum){
        if(sum<0) return 0;
        if(ind==num2.size())return 1;
        if(dp[ind][tight1][tight2][sum]!=-1){
            return dp[ind][tight1][tight2][sum];
        }
        ll low=(tight1)?num1[ind]-'0':0;
        ll high=(tight2)?num2[ind]-'0':9;
        int count=0;
        for(int i=low;i<=high;i++){
            count=(count%mod+solve(ind+1,tight1 & (i==low),tight2 & (i==high),num1,num2,sum-i)%mod)%mod;
        }
        return dp[ind][tight1][tight2][sum]=count;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        ll a1=num1.size();
        ll a2=num2.size();
        ll d=a2-a1;
        string extra="";
        while(d--){
            extra+='0';
        }
        extra+=num1;
        memset(dp,-1,sizeof(dp));
        int a=solve(0,1,1,extra,num2,min_sum-1);
        memset(dp,-1,sizeof(dp));
        int b=solve(0,1,1,extra,num2,max_sum);
        ll ans=(b-a)%mod;
        return (ans<0)?ans+mod:ans;
    }
};