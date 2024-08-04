class Solution {
public:
    int mod=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>new_arr;
        for(int i=0;i<nums.size();i++){
            new_arr.push({nums[i],i});
        }
        int ans=0;
        int a=0;
        while(!new_arr.empty()){
            int val=new_arr.top().first;
            int index=new_arr.top().second;
            if(a>=left-1 && a<=right-1){
                ans=(ans%mod+val%mod)%mod;
            }
            if(a>right-1) break;
            new_arr.pop();
            if(index+1<n){
                new_arr.push({val+nums[index+1],index+1});
            }
            a++;
        }
        return ans;
    }
};