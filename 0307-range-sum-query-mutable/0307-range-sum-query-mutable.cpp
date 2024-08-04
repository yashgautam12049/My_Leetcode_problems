class NumArray {
public: 
    int n;
    vector<int>seg_tree;
    void build_segment_tree(vector<int>& nums,int i,int l,int r){
        if(l==r){
            seg_tree[i]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        build_segment_tree(nums,2*i+1,l,mid);
        build_segment_tree(nums,2*i+2,mid+1,r);
        seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
    }
    void update_seg_tree(int index,int val,int i,int l,int r){
        if(l==r){
            seg_tree[i]=val;
            return;
        }

        int mid=l+(r-l)/2;
        if(index<=mid){
        update_seg_tree(index,val,2*i+1,l,mid);
        }
        else{
        update_seg_tree(index,val,2*i+2,mid+1,r);
        }
        seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
    }

    int query_sum(int i,int left,int right,int l,int r){
        if(l>right || r<left) return 0;
        if(l>=left && r<=right){
            return seg_tree[i];
        }
        int mid=l+(r-l)/2;
        return query_sum(2*i+1,left,right,l,mid)+query_sum(2*i+2,left,right,mid+1,r);
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg_tree.resize(4*n);
        build_segment_tree(nums,0,0,n-1);
    }
    
    void update(int index, int val) {
        update_seg_tree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query_sum(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */