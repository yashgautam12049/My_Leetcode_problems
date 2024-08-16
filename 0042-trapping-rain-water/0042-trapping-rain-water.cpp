class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>next_greater_element_from_left(n);
        vector<int>next_greater_element_from_right(n);
        int curr=height[0];
        for(int i=0;i<n;i++){
            curr=max(curr,height[i]);
            next_greater_element_from_left[i]=curr;
        }
        curr=height[n-1];
        for(int i=n-1;i>=0;i--){
            curr=max(curr,height[i]);
            next_greater_element_from_right[i]=curr;
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            ans+=(min(next_greater_element_from_left[i],next_greater_element_from_right[i])-height[i]);
        }
        return ans;
    }
};