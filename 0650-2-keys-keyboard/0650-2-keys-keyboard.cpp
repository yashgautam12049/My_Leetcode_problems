class Solution {
public:
int solve(int copytopaste,int paste,int n){
    if(copytopaste>n){
        return 100000;
    }
    if(copytopaste==n){
        return 0;
    }
    int a=2+solve(copytopaste+copytopaste,copytopaste,n);
    int b=1+solve(copytopaste+paste,paste,n);
    return min(a,b);
}
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        return 1+solve(1,1,n);
    }
};