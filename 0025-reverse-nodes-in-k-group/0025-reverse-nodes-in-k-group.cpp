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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        
        int count = 0;
        ListNode *temp = head;
        while(temp != nullptr && count < k) {
            temp = temp->next;
            count++;
        }
        
        if(count < k) // If the remaining nodes are less than k, no need to reverse
            return head;
        
        count = 0;
        while(curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next != nullptr) // Recursively call reverseKGroup for the next group
            head->next = reverseKGroup(next, k);
        
        return prev; // Prev will be the new head of the reversed group
    }
};
