class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>v=arr;
        sort(v.begin(),v.end());
        map<int,int>mp;
        int a=1;
        for(int i=0;i<arr.size();i++){
            if(mp.find(v[i])==mp.end()){
                 mp[v[i]]=a;
                 a++;
            }
           
        }
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }
};