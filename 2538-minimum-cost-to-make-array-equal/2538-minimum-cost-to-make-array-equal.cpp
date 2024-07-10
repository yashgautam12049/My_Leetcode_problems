using ll=long long;
class Solution {
public:
    ll cal(ll mid,vector<int>& nums, vector<int>& cost){
        ll amount=0;
        for(int i=0;i<nums.size();i++){
            amount+=(cost[i]*(abs(mid-nums[i])));
        }
        return amount;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll low=*min_element(nums.begin(),nums.end());
        ll high=*max_element(nums.begin(),nums.end());
        ll n=nums.size();
        ll amount=1e12;
        while(low<=high){
            ll mid=low+(high-low)/2; //equal
            ll cost1=cal(mid,nums,cost);
            ll cost2=cal(mid+1,nums,cost);
            amount=min(cost1,cost2);
            if(cost1<cost2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return amount;
    }
};