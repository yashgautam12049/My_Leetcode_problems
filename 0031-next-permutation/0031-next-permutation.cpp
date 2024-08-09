class Solution {
public:
    int just_greater(vector<int>& temp, int num) {
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] > num) {
                return temp[i];
            }
        }
        return -1;
    }
    int index(vector<int>& nums,int num){
        int ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num){
                ans=i;
            }
        }
        return ans;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[n-1]);
        int after;
        for (int i = n - 2; i >= 0; i--) {
            sort(temp.begin(), temp.end());
            if (just_greater(temp, nums[i]) != -1) {
                int ind=index(nums,just_greater(temp, nums[i]));
                swap(nums[i],nums[ind] );
                after = i;
                break;
            }
            else{
                temp.push_back(nums[i]);
            }
        }
        sort(nums.begin() + after + 1, nums.end());
    }
};