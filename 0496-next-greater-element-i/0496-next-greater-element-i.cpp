class Solution {
public:
    int index(int target,vector<int>& nums2){
        for(int i=0;i<nums2.size();i++){
            if(target==nums2[i]){
                return i;
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st; 
        int n=nums2.size();
        map<int,int>store;
        vector<int>result;
        //next greater element
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(nums2[i]);
                store[nums2[i]]=-1;
            }
            else{
                store[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        for(auto it:nums1){
            result.push_back(store[it]);
        }
        return result;
    }
};