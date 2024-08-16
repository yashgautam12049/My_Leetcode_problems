class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int,int>>temp;
        int pos=0;
        for(auto it:arrays){
            int n=it.size();
            int first=it[0];
            int last=it[n-1];
            temp.push_back({first,pos});
            temp.push_back({last,pos});
            pos++;
        }
        sort(begin(temp),end(temp));
        int size=temp.size();
        int i=0;
        int j=size-1;
        int temp_i=i;
        int temp_j=j;
        while(temp[temp_i].second==temp[j].second && i<j){
            temp_i++;
        }
        while(temp[i].second==temp[temp_j].second && i<j){
            temp_j--;
        }

        return max(temp[j].first-temp[temp_i].first,temp[temp_j].first-temp[i].first);
    }
};