class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(minutesToTest<minutesToDie) return 0;
        int pair=minutesToTest/minutesToDie;
        int pig=0;
        // int t=1;
        int a=1;
        while(pow(pair+1,pig)<buckets){
            // a=pow(pair+1,pig);
            pig++;
            // t++;
        }
        return pig;
    }
};