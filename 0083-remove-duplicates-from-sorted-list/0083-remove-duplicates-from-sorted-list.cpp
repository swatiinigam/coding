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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* forw = curr->next;
            if (curr->val == forw->val) {
                // Skip all duplicate nodes
                while (forw != nullptr && curr->val == forw->val) {
                    forw = forw->next;
                }
                curr->next = forw; // Link to the next unique value
            } else {
                curr = curr->next; // Move to the next node
            }
        }
        
        return head;
    }
};
