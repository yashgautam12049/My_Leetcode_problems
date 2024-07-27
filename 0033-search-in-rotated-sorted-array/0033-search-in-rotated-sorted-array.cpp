#define pb push_back
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //apply 2 times BS
        vector<int>v1;
        // vector<int>v2;
        int result=-1;
        int i;
        int n=nums.size();
        for (i = 0; i < n - 1; i++) {
            v1.pb(nums[i]);
            if (nums[i] > nums[i + 1]) {
                break;
            }
        }
        v1.pb(nums[i]);
        if(v1[v1.size()-1]>=target && v1[0]<=target){
            int low=0;
            int high=v1.size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(v1[mid]>target){
                    high=mid-1;
                }
                else if(v1[mid]<target){
                    low=mid+1;
                }
                else if(v1[mid]==target){
                    result=mid;
                    break;
                }
            }
        }
        else{
            int low=i+1;
            int high=nums.size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(nums[mid]>target){
                    high=mid-1;
                }
                else if(nums[mid]<target){
                    low=mid+1;
                }
                else if(nums[mid]==target){
                    result=mid;
                    break;
                }
            }
        }
        return result;
    }
};