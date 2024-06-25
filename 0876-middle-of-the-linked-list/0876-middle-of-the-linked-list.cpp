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
        int len=0;
        ListNode*temp=head;
        while(temp!=nullptr){
            temp=temp->next;
             len+=1;
        }
        int mid=len/2;
        int k=0;
          ListNode*temp1=head;
        while(k!=mid){
            temp1=temp1->next;
            k++;
            
        }
        return temp1;
    }
};