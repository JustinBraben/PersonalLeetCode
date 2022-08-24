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
        if (!head) return nullptr;

        // Use a pointer to the head of the list
        // we do not alter the head pointer so it can be
        // returned at the end of the function
        auto p = head;

        // Traverse the linked list with the pointer initialized
        while (p->next != NULL) {

            // In the event a duplicate is found
            // change the link to p->next->next
            // need a temp variable to delete the duplicate
            // and avoid memory leak
            if (p->val == p->next->val) {

                auto temp = p->next;
                p->next = temp->next;
                delete temp;

            }
            // only move along the linked list when the 
            // next value is not a duplicate
            else {
                p = p->next;
            }

        }

        return head;
    }
};