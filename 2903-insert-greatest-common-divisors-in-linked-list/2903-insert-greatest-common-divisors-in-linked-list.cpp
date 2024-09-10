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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*temp=head;
        while(temp!=NULL && temp->next!=NULL){
            ListNode*next=temp->next;
            int val=__gcd(temp->val,next->val);
            ListNode*dummy=new ListNode(val);
            temp->next=dummy;
            dummy->next=next;
            temp=next;
            next=next->next;
        }
        return head;
    }
};