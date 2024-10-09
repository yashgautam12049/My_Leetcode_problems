class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<j){
            int h=min(height[i],height[j]);
            if(h==height[i]){
                ans=max(ans,h*(j-i));
                i++;
            }else{
                ans=max(ans,h*(j-i));
                j--;
            }
        }
        return ans;
    }
};