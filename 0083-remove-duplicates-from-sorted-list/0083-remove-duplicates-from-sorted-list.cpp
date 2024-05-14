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
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* curr = head;
        ListNode* temp = curr->next;
        
        while (temp != nullptr) {
            if (curr->val == temp->val) {
                if (temp->next != nullptr) {
                    temp = temp->next;
                    curr->next = temp;
                } else {
                    curr->next = nullptr;
                    break;
                }
            } else {
                temp = temp->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
