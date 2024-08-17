class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long n=points.size();
        long long m=points[0].size();
        vector<long long>prev(m);
        for(long long i=0;i<m;i++){
            prev[i]=points[0][i];
        }
        for(long long i=1;i<n;i++){
        vector<long long>left(m);
        vector<long long>right(m);
        left[0]=prev[0];
        for(long long j=1;j<m;j++){
            left[j]=max(prev[j],left[j-1]-1);
        }
        right[m-1]=prev[m-1];
        for(long long j=m-2;j>=0;j--){
            right[j]=max(prev[j],right[j+1]-1);
        }
        // vector<long long>curr(m);
        for(long long k=0;k<m;k++){
        prev[k]=points[i][k]+max(left[k],right[k]);
        }
        // prev=curr;
        }
        return *max_element(prev.begin(),prev.end());
    }
};