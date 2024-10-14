class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        long long score = 0;
        while(k>0){
            int ele = pq.top();
            pq.pop();
            score += ele;
            pq.push(ceil(ele/3.0));
            k--;
        }
        return score;
    }
};