class Solution {
public:
    long long just_greater(vector<long long>& temp, long long num) {
        for (long long i = 0; i < temp.size(); i++) {
            if (temp[i] > num) {
                return temp[i];
            }
        }
        return -1;
    }
    long long index(vector<long long>& nums,long long num){
        long long ans;
        for(long long i=0;i<nums.size();i++){
            if(nums[i]==num){
                ans=i;
            }
        }
        return ans;
    }
    long long nextGreaterElement(int m) {
        vector<long long>nums;
        long long N=m;
        while(m!=0){
            nums.push_back(m%10);
            m=m/10;
        }
        reverse(nums.begin(),nums.end());
        long long n = nums.size();
        vector<long long> temp;
        temp.push_back(nums[n-1]);
        long long after;
        for (long long i = n - 2; i >= 0; i--) {
            sort(temp.begin(), temp.end());
            if (just_greater(temp, nums[i]) != -1) {
                long long ind=index(nums,just_greater(temp, nums[i]));
                swap(nums[i],nums[ind] );
                after = i;
                break;
            }
            else{
                temp.push_back(nums[i]);
            }
        }
        sort(nums.begin() + after + 1, nums.end());
        long long ans=0;
        // reverse(nums.begin(),nums.end());
        for(long long i=0;i<nums.size();i++){
            ans+=nums[i];
            ans=ans*10;
        }
        ans/=10;
        if(ans>N && N<2147483647 && ans<=2147483647){
            return ans;
        }
        return -1;
    }
};