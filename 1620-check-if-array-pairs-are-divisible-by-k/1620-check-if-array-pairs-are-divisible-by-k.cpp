class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int>mp;
        // mp[5]=INT_MAX;
        for(int i=0;i<n;i++){
            arr[i]%=k;
            if(arr[i]<0){
                arr[i]+=k;
            }
        }
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            if(it.first==0){
                if(mp[it.first]%2!=0){
                return 0;
            }
            }
            else if(mp[it.first]!=mp[k-it.first]){
                return 0;
            }
        }
        // for(int i=0;i<n;i++){
        //     if(mp.find(k-arr[i])!=mp.end()){
        //         mp[arr[i]]--;
        //         mp[k-arr[i]]--;
        //         if(mp[arr[i]]==0){
        //             mp.erase(arr[i]);
        //         }
        //         if( && mp.find(k-arr[i])!=mp.end() && mp[k-arr[i]]==0){
        //             mp.erase(k-arr[i]);
        //         }
        //     }
        //     else{
        //         return 0;
        //     }
        // }
        return 1;
    }
};