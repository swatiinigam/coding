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
private:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        
        ListNode* midNode = findMid(head);
        ListNode* secondHalf = reverseList(midNode->next);
        midNode->next = nullptr;
        
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return true;
    }
};
