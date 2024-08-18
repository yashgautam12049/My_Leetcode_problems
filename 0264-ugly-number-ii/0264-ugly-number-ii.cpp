class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>result(n+1);
        int i2=1,i3=1,i5=1;
        result[1]=1;
        for(int i=2;i<=n;i++){
            int mul_2=result[i2]*2;
            int mul_3=result[i3]*3;
            int mul_5=result[i5]*5;
            result[i]=min({mul_2,mul_3,mul_5});
            if(result[i]==mul_2){
                i2++;
            }
            if(result[i]==mul_3){
                i3++;
            }
            if(result[i]==mul_5){
                i5++;
            }
        }
        return result[n];
    }
};