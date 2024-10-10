class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int>max_to_right(n);
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,nums[i]);
            max_to_right[i]=maxi;
        }
        int i=0,j=0;
        int ans=INT_MIN;
        while(j<n && i<n){
            
            while(j<n && i<n && nums[i]>max_to_right[j]){
                i++;
            }
            
            ans=max(ans,j-i);
                j++;
            
        }
        return ans;
    }
};