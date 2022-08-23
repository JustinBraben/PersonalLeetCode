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
    ListNode* removeElements(ListNode* head, int val) {
        // return the head if you've reached the end of the linked list
        // also works if the linked list is just empty
        if (head == NULL) return head;

        head->next = removeElements(head->next, val);

        // If the current value of the linked list is the value we are removing
        // return the next value
        // because of recursion, even if the next value is also a value we are removing
        // the recursion will keep calling removeElements until you are at NULL or 
        // the next allowed value in the linked list
        return (head->val == val) ? head->next : head;
    }
};