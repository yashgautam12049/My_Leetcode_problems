class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1){
            return '0';
        }
        int len=1;
        for(int i=2;i<=n;i++){
            len=(2*len)+1;
        }
        if(len/2==k-1){
            return '1';
        }
        if(len/2>k-1){
            return findKthBit(n-1,k);
        }
        
        return findKthBit(n-1,len-k+1)=='0'?'1':'0';
    }
};