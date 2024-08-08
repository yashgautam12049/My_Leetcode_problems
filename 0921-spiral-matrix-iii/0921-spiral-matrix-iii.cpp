class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        vector<vector<int>>direction={{0,1},{1,0},{0,-1},{-1,0}};
        int step=0;
        int dir=0;
        ans.push_back({rStart,cStart});
        while(ans.size()!=rows*cols){
            if(dir==0 || dir==2){
                step++;
            }

        for(int i=0;i<step;i++){//row constant
            rStart+=direction[dir][0];
            cStart+=direction[dir][1];
            if(rStart<rows && cStart<cols && rStart>=0 && cStart>=0){
            ans.push_back({rStart,cStart});
            }
        }
          dir=(dir+1)%4; 
        }
        return ans;
    }
};