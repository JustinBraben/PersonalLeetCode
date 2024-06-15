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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // If one list happens to be empty, return the other list
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode* result = list1;

        // start the list with the lowest val
        // if they are the same val start with list1
        if (list1->val > list2->val) {
            result = list2;
            list2 = list2->next;
        }
        else {
            list1 = list1->next;
        }

        ListNode* current = result;

        // til one list reaches null
        while (list1 && list2) {

            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        // in the case one list reached null (shorter linked list)
        // add the rest of the other linked list to the end
        if (!list1)
            current->next = list2;
        else
            current->next = list1;

        return result;
    }
};