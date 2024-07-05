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
// #define push_back as pb;
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1}; // Less than 3 nodes

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* after = curr->next;
        int i = 1;  // index of curr
        vector<int> v;

        while (after) {
            if ((curr->val > prev->val && curr->val > after->val) || 
                (curr->val < prev->val && curr->val < after->val)) {
                v.push_back(i);
            }
            prev = curr;
            curr = after;
            after = after->next;
            i++;
        }

        int n = v.size();
        if (n >= 2) {
            int minDist = INT_MAX;
            for (int j = 1; j < n; ++j) {
                minDist = min(minDist, v[j] - v[j-1]);
            }
            int maxDist = v[n-1] - v[0];
            return {minDist, maxDist};
        } else {
            return {-1, -1};
        }
    }
};