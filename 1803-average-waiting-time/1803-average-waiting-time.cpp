#define pb push_back
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<int>time;
        int temp=customers[0][0];
        for(auto it:customers){
            int arrive=it[0];
            int w_time=it[1];
            if(arrive>temp){
                temp=arrive+w_time;
            }
            else{
            temp+=w_time;
            }
            time.pb(temp-arrive);
        }
        long double sum=accumulate(time.begin(),time.end(),0ll);
        long double n=time.size();
        long double ans=sum/n;
        return ans;
    }
};