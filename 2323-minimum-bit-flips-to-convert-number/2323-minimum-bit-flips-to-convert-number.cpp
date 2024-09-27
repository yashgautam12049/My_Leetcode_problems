class Solution {
public:
    int minBitFlips(int start, int goal) {
        int Xor=start^goal;
        int ans=0;
        while(Xor!=0){
            ans+=(Xor&1);
            Xor=Xor>>1;
        }
        return ans;
    }
};