class Solution {
public:
    double check(vector<int>& dist,int mid){
        double ans=0.0;
        for(int i=0;i<dist.size();i++){
            double temp;
            if(i==dist.size()-1){
                double a=double(dist[i])/mid;
                temp=a;
            }//correct
            else{
                int a;
            if(double(dist[i])/mid!=dist[i]/mid){
                a=double(dist[i])/mid+1;
            }//correct
            else{
                a=double(dist[i])/mid;
            }//correct
            temp=double(a);
            }
            ans+=(temp);
        }
        return ans;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=1e7;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(check(dist,mid)<=hour){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};