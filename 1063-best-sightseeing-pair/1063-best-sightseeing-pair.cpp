class Solution {
public:
    
    int maxScoreSightseeingPair(vector<int>& values) {
        //taking arr[i]+i
        vector<int>arr_i;
        int n=values.size();
        int a=0;
        int ind;
        for(int i=0;i<n-1;i++){
            a=max(a,values[i]+i);
            arr_i.push_back(a);
            // values[i]+i
        }
        int result=0;
        for(int j=1;j<n;j++){
            result=max(result,arr_i[j-1]+values[j]-j);
        }
        return result;
    }
};