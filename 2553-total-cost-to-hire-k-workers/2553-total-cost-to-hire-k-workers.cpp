using ll=long long;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;
        long long n=costs.size();
        long long i=0;
        long long j=n-1;
        long long ans=0;
        while( k--){
            long long k1=candidates;
            while(k1-- && pq1.size()!=candidates && i<=j){
                pq1.push(costs[i]);
                i++;
            }
            long long m=candidates;
            while(m-- && pq2.size()!=candidates && i<=j){
                pq2.push(costs[j]);
                j--;
            }
            long long min_pq1=pq1.size()>0?pq1.top():INT_MAX;
            long long min_pq2=pq2.size()>0?pq2.top():INT_MAX;
            if(min_pq2<min_pq1){
                ans+=pq2.top();
                pq2.pop();
            }
            else{
                ans+=pq1.top();
                pq1.pop();
            }
            // ans+=pq2.top()<pq1.top()?pq2.top():pq1.top();
        }
        // if(k!=0){
            // while(k--){
            //     if(pq2.top()<pq1.top()){
            //     ans+=pq2.top();
            //     pq2.pop();
            // }
            // else{
            //     ans+=pq1.top();
            //     pq1.pop();
            // }
            // }
        // }
        return ans;
    }
};