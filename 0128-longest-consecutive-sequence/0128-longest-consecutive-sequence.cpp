class Solution {
public:
    int number(int target,map<int,bool>&mp){
        if(mp.find(target)==mp.end()){
            return 0;
        }
        return 1+number(target+1,mp);
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        map<int,bool>mp;
        for(auto it:nums){
            mp[it]=false;
        }
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-1)==mp.end()){
                mp[nums[i]]=true;
            }
        }
        int result=1;
        for(auto it:mp){
            if(it.second){
                result=max(result,number(it.first,mp));
            }
        }
        return result;
    }
};