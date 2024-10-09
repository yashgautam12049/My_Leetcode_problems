class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int n = height.size();
        int r = n - 1;
        int maxarea = 0;
        int area = 0;
        int maxlen = 0;
        int breadth = 0;

        while (l < r) {
            // Calculate the minimum height between the two pointers
            maxlen = min(height[l], height[r]);
            
            // Calculate the breadth (distance between the two pointers)
            breadth = r - l;

            // Calculate the area
            area = maxlen * breadth;

            // Update the maximum area found so far
            maxarea = max(maxarea, area);

            // Move the pointer pointing to the smaller height
            if (height[l] < height[r]) {
                l++; // Move left pointer to the right
            } else {
                r--; // Move right pointer to the left
            }
        }

        return maxarea;
    }
};
