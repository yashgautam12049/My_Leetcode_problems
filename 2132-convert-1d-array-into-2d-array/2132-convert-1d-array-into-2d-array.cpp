class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>v;
        if(original.size()!=m*n){
            return v;
        }
        int t=n;
        int ctr=0;
        for(int i=0;i<m;i++){
            vector<int>row;
            while(n--){
                if(ctr<original.size()){
                row.push_back(original[ctr]);
                ctr++;
                }
                else break;
            }
            n=t;
            v.push_back(row);
        }
        return v;
    }
};