/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>grid(m,vector<int>(n,-1));
        int top=0;
        int bottom=m-1;
        int front=0;
        int back=n-1;
        int dir=0;
        while(head!=NULL){
            if(dir==0){
            for(int i=front;i<=back && head!=NULL;i++){
            grid[top][i]=head->val;//right
            head=head->next;
            }
            top++;
            }
            else if(dir==1){
            for(int i=top;i<=bottom && head!=NULL;i++){
            grid[i][back]=head->val; //down
            head=head->next;
            }
            back--;
            }
            else if(dir==2){
            for(int i=back;i>=front && head!=NULL;i--){
            grid[bottom][i]=head->val; //left
            head=head->next;
            }
            bottom--;
            }
            else if(dir==3){
            for(int i=bottom;i>=top && head!=NULL;i--){
            grid[i][front]=head->val; //up
            head=head->next;
            }
            front++;
            }
            dir++;
            if(dir==4){
                dir=0;
            }
            
        }
        return grid;
    }
};