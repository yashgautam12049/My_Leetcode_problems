class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        int len=1;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ans){
               temp++;
            }
            else{
                len=max(temp,len);
                temp=0;
            }
        }
        return max(temp,len);
    }
};