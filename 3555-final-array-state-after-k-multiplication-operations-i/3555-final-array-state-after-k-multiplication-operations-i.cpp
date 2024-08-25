class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        while(k--){
        int b=*min_element(nums.begin(),nums.end());
        int t=0;
        int i=0;
            while(i<n){
                if(t==1){
                    i=n;
                    continue;
                }
                if(nums[i]==b){
                    nums[i]=nums[i]*multiplier;
                    t++;
                }
                i++;
            }
        }
        return nums;
    }
};