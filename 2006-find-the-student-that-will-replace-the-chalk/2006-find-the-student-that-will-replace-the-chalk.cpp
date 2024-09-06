using ll=long long;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll sum=accumulate(chalk.begin(),chalk.end(),0ll);
        ll n=chalk.size();
        if(k%sum==0){
            return 0;
        }
        else{
            ll remaining=k%sum;
            for(ll i=0;i<n;i++){
                if(remaining<chalk[i]){
                    return i;
                }
                remaining-=chalk[i];
            }
        }
        return 0;
    }
};