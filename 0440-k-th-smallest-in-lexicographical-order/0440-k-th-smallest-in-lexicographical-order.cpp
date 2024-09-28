class Solution {
public:
long long Count(long long curr,long long next,long long n){
    long long currnum=0;
    while(curr<=n){
        currnum+=(next-curr);
        curr*=10;
        next*=10;
        next=min(next,n+1);
    }
    return currnum;
}
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k!=0){
            long long count=Count(curr,curr+1,n);
            if(count<=k){
                curr++;
                k-=count;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};