class Solution {
public:
    
    bool isReachable(int targetX, int targetY) {
        while(targetX%2==0){
            targetX=targetX/2;
        }
        while(targetY%2==0){
            targetY=targetY/2;
        }
        if(targetX==1 || targetY==1) return 1;
        if(targetY==targetX) return 0;
        if(targetX%2!=0 && targetY%2!=0){
            if(targetX-1<targetY){
                targetY=targetY+targetX;
            }
            else{
                targetX=targetY+targetX;
            }
        }
        
        return isReachable(targetX,targetY);
    }
};