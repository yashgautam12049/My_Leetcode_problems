class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int result=0;
        int flip_count=0;
        vector<int>flipped(n,0);
        for(int i=0;i<n;i++){
            if(i>=k && flipped[i-k]==1){
                flip_count--;
            }
            if(flip_count%2==0){

                if(nums[i]==0){
                    if(i+k>n){
                        return -1;
                    }
                    flip_count++;
                    result++;
                    flipped[i]=1;
                }
            }else{
                if(nums[i]==1){
                    if(i+k>n){
                        return -1;
                    }
                    flip_count++;
                    result++;
                    flipped[i]=1;
                }
            }
        }
        return result;
    }
};