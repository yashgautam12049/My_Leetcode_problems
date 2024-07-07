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
// #define push_back as pb;
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        head=head->next;
         ListNode* after=head->next;
        int i=1;
        vector<int>v;
        while(head->next!=NULL){
            if(head->val>prev->val && head->val>after->val){
                v.push_back(i);
            }
            else if(head->val<prev->val && head->val<after->val){
                v.push_back(i);
            }
            prev=head;
            if(head->next!=NULL) head=head->next;
            if(after->next!=NULL) after=after->next;
            i++;
        }
        int n=v.size();
        int a=INT_MAX;
        for(int i=1;i<n;i++){
            a=min(a,v[i]-v[i-1]);
        }
        if(n>=2){
        return {a,v[n-1]-v[0]};
        }
        else{
            return {-1,-1};
        }

    }
};