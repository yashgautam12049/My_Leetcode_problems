class Solution {
public:
    bool check(int a,int b){
        string a_=to_string(a);
        string b_=to_string(b);
        if(a_.size()>b_.size()){
            while(b_.size()!=a_.size()){
                b_='0'+b_;
            }
        }
        if(b_.size()>a_.size()){
            while(a_.size()!=b_.size()){
                a_='0'+a_;
            }
        }
        int n=a_.size();
        int t=0;
        for(int i=0;i<n;i++){
            if(a_[i]!=b_[i]){
                t++;
            }
        }
        int ok=0;
        sort(a_.begin(),a_.end());
        sort(b_.begin(),b_.end());
        if(a_==b_){
            ok++;
        }
        if((t==2 || t==0) && ok==1){
            return true;
        }
        return 0;
    }
    int countPairs(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(nums[i],nums[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};