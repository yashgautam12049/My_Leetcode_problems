class Solution {
public:
    int minSubarray(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        int n=nums.size();
        int result=INT_MAX;
        int sum=0;
        map<int,int>mp;
        mp[0]=-1;

        int initial_sum=0;
        for(auto it:nums){
            initial_sum=(initial_sum+it)%k;
        }
        int rem=initial_sum%k;
        if(rem==0){
            return 0;
        }
        int curr=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%k;//curr
            nums[i]=(sum+k)%k;//to avoid negetive number
            int prev=(nums[i]-rem+k)%k;
            if(mp.find(prev)!=mp.end()){
                result=min(result,i-mp[prev]);
            }
            cout<<nums[i]<<" "<<i<<endl;
            mp[nums[i]]=i;
        }
        return (result==n)?-1:result;
    }
};