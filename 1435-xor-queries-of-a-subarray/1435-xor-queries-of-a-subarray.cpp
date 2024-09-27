using ll=long long;
class Solution {
public:
    void buildsegmentree(ll i,ll l,ll r,vector<ll>&v,vector<int>&orignal){
        int mid=l+(r-l)/2;
        if(l==r){
            v[i]=orignal[l];
            return;
        }
        buildsegmentree(2*i+1,l,mid,v,orignal);
        buildsegmentree(2*i+2,mid+1,r,v,orignal);
        v[i]=v[2*i+1]^v[2*i+2];
    }
    int queryupdate(ll i,ll start,ll end,ll l,ll r,vector<ll>&v){
        
        if(start>=l && end<=r){
            return v[i];
        }
        if(start>r || end<l){
            return 0;
        }
        ll mid=start+(end-start)/2;
        ll ans1=queryupdate((2*i)+1,start,mid,l,r,v);
        ll ans2=queryupdate((2*i)+2,mid+1,end,l,r,v);
        return ans1^ans2;
    }
    
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ll n=arr.size();
        vector<ll>v(4*n);
        buildsegmentree(0,0,n-1,v,arr);
        vector<int>ans;
        for(auto it:queries){
            ll start=it[0];
            ll end=it[1];
            ans.push_back(queryupdate(0,0,n-1,start,end,v));
        }
        return ans;
    }
};