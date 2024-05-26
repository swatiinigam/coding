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
    // Function to create a sorted linked list from a sorted vector of ListNode pointers
    ListNode* createList(vector<ListNode*>& v) {
        if (v.empty()) return nullptr;
        ListNode* root = v[0];
        ListNode* current = root;
        for (int i = 1; i < v.size(); ++i) {
            current->next = v[i];
            current = current->next;
        }
        current->next = nullptr; // Make sure the last node points to nullptr
        return root;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> v;

        // Flatten the list of lists into a single list of ListNode pointers
        for (int i = 0; i < lists.size(); ++i) {
            ListNode* node = lists[i];
            while (node != nullptr) {
                v.push_back(node);
                node = node->next;
            }
        }

        // Sort the list of ListNode pointers based on node values
        sort(v.begin(), v.end(), [](ListNode* a, ListNode* b) {
            return a->val < b->val;
        });

        // Create a sorted linked list from the sorted vector
        return createList(v);
    }
};