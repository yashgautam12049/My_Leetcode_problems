class Solution {
public:
int dp[1001][1001];
int width;
    int solve(int ind,vector<vector<int>>& books,int shelfWidth,int maxH){
        int n=books.size();
        if(ind==n){
            return maxH;
        }
        if(dp[ind][shelfWidth]!=-1){
            return dp[ind][shelfWidth];
        }
        //take
        int take=INT_MAX;
        // int not_take=INT_MAX;
        if(shelfWidth>=books[ind][0]){
        take=solve(ind+1,books,shelfWidth-books[ind][0],max(maxH,books[ind][1]));
        }
        int not_take=maxH+solve(ind+1,books,width-books[ind][0],books[ind][1]);
        return dp[ind][shelfWidth] = min(take,not_take);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        width=shelfWidth;
        int n=books.size();
        return solve(0,books,shelfWidth,0);
    }
};