class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>capital_profit;
        int n=profits.size();
        for(int i=0;i<n;i++){
            capital_profit.push_back({capital[i],profits[i]});
        }
        sort(capital_profit.begin(),capital_profit.end());
        int i=0;
        priority_queue<int>pq;
        for(int j=0;j<k;j++){
            while(i<n && capital_profit[i].first<=w){
                pq.push(capital_profit[i].second);
                i++;
            }
            if(pq.empty()){
                break;
            }
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};