class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int n=nums.size();
        int sum=0;
        int result=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum%k<0){
            nums[i]=(sum%k)+k;
            }else{
                nums[i]=(sum%k);
            }
            if(mp.find(nums[i])!=mp.end()){
            result+=mp[nums[i]];
            }
            mp[nums[i]]++;
        }
        return result;
    }
};