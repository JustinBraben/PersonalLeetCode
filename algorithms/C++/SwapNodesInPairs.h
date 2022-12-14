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
    ListNode* swapPairs(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* temp = head->next;; // temporary pointer to store head -> next

        head->next = swapPairs(head->next->next); // changing links

        // This happens backwards because of recursion, so later
        // nodes are swapped before earlier nodes which is important
        temp->next = head; // put temp -> next to head

        return temp;
    }
};