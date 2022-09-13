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
    bool hasCycle(ListNode* head) {

        auto* slow = head, * fast = head;

        // Will keep looping so long as both fast and fast->next are not null
        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }

        // If you found a null you will leave the top loop
        // and return false
        return false;
    }
};