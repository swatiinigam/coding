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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        int len = 1;
        ListNode *temp = head;
        
        // Find the length of the list and locate the last node
        while (temp->next) {
            temp = temp->next;
            len++;
        }
        
        // Make the list circular
        temp->next = head;
        
        // Calculate the actual rotation point
        k = len - k % len;
        
        // Find the new tail of the rotated list
        for (int i = 0; i < k; i++) {
            temp = temp->next;
        }
        
        // Update the head and break the circular list
        head = temp->next;
        temp->next = nullptr;
        
        return head;
    }
};
