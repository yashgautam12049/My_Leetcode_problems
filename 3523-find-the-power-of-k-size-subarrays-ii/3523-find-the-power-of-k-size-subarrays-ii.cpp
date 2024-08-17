class Solution {
public:
    // int noofconsecutive(int i,int j,vector<int>& nums){
    //     int last=nums[j]-1;
    //     int ans=1;
    // for(int start=j-1;start>=i;start--){
    //     if(nums[start]==last){
    //         ans++;
    //     }
    //     else{
    //         break;
    //     }
    //     last--;
    // }
    // return ans;
    // }
    // bool consecutive(int i,int j,vector<int>& nums){
    //     int first=nums[i]+1;
    // for(int start=i+1;start<=j;start++){
    //     if(nums[start]!=first){
    //         return 0;
    //     }
    //     first++;
    // }
    // return 1;
    // }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1){
            return nums;
        }
        vector<int>temp_arr(n,0);
        vector<int>result;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1){
                temp_arr[i]=1;
            }
        }
        int i=1;
        int cnt=0;
        int j;
        //check if from first k consecutive element are there or not
        for(j=0;j<k;j++){
            if(temp_arr[j]==1){
                cnt++;
            }
        }
        if(cnt>0){
            result.push_back(-1);
        }
        else{
            result.push_back(nums[k-1]);
        }
        while(j<n){
            if(temp_arr[j]==1){
                cnt++;
            }
            if(temp_arr[i]==1){
                cnt--;
            }
            if(cnt>0){
                result.push_back(-1);
            }
            else{
                result.push_back(nums[j]);
            }
            j++;
            i++;
        }
        return result;
    }
};