class Solution {
public:
    int check(vector<int>& nums,int mid){
        int n=nums.size();
        int count=0;
        int i=0;
        int j=1;
        while(j<n){
        if(nums[j]-nums[i]<=mid && i<j){
            count+=(j-i);
            j++;
        }
        else if(i==j){
            j++;
        }
        else{
            i++;
        }
        }
return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int distance=nums[n-1]-nums[0];
        int result=0;
        //binary search
        int low=0;
        int high=distance;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid)<k){
                low=mid+1;
            }
            else{
                result=mid;
                high=mid-1;
            }
            
        }
        return result;
    }
};