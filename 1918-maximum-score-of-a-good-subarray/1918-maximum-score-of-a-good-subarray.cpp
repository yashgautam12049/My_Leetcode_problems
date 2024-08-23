class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k;//see left part
        int j=k;//see right part
        int n=nums.size();
        int curr_min=nums[i];
        int result=nums[i];
        while(i>0 || j<n-1){
            int leftval=(i>0)?nums[i-1]:0;
            int rightval=(j<n-1)?nums[j+1]:0;
            if(leftval>rightval){
                i--;
                curr_min=min(curr_min,nums[i]);
            }
            else{
                j++;
                curr_min=min(curr_min,nums[j]);
            }
            
            result=max(result,curr_min*(j-i+1));
        }
       
        return result;
    }
};