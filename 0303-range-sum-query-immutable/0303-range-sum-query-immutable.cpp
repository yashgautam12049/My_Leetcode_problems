class NumArray {
public:
vector<int>str;
    int getsumrange(int i,int left, int right,int start,int end){
        if(start>right || end<left) return 0;
        if(start>=left && end<=right){
            return str[i];
        }
        int mid=start+(end-start)/2;
        return getsumrange(2*i+1,left,right,start,mid)+getsumrange(2*i+2,left,right,mid+1,end);
    }
    void construct(vector<int>& nums,int i,int low,int high){
        if(low==high){
            str[i]=nums[low];
            return ;
        }
        int mid=low+(high-low)/2;
        construct(nums,2*i+1,low,mid);
        construct(nums,2*i+2,mid+1,high);
        str[i]=str[2*i+1]+str[2*i+2];
    }
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        str.resize(4*n);
        construct(nums,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return getsumrange(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */