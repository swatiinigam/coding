/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head||!head->next || !head->next->next) 
            return 0;
        ListNode *fast=head, *slow=head;
        //int i=0;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        //    cout<<++i<<",";
            if (fast==slow) return 1;
        }
        return 0;
    }
};