/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
/*
 * Given the head of a singly linked list, return the middle node of the linked list.
 * If there are two middle nodes, return the second middle node. 
 * 
 */
public class Solution
{
    public ListNode MiddleNode(ListNode head)
    {
        ListNode result = null;

        int size = 0;
        ListNode temp = head;
        while (temp != null)
        {
            temp = temp.next;
            size++;
        }

        temp = head;
        int count = 0;

        while (temp != null)
        {
            if (count == size / 2)
            {
                result = temp;
                return result;
            }
            temp = temp.next;
            count++;
        }

        return result;
    }
}