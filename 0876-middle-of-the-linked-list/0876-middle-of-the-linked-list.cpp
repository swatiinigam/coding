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
    ListNode* middleNode(ListNode* head) {
        ListNode*temp=head;
        int len=0;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        int k=len/2;
        ListNode*curr=head;
        for(int i=0;i<k;i++){
          curr=curr->next;  
        }
        
        return curr;
        
    }
};