class Solution {
public:
    long long divide(long long dividend, long long divisor) {
        long long ans=0;
        if(dividend==divisor){
            return 1;
        }
        long long sign=(dividend<0)^(divisor<0)?-1:1;
        dividend=abs(dividend);
        divisor=abs(divisor);
   
            while(dividend>=divisor){
            int cnt=0;
                while(dividend>=(divisor<<cnt+1)){
                cnt++;
                }
                dividend-=(divisor<<cnt);
                ans+=(1ll<<cnt);
            }
        if(sign*ans>INT_MAX){
            return INT_MAX;
        }else if(sign*ans<0){
            if(sign*ans<INT_MIN){
                return INT_MIN;
            }
        }
        
        return sign*ans;
    }
};