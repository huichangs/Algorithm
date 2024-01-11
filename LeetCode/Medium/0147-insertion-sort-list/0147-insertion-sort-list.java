/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        if(head == null){
            return null;
        }

        ListNode curr = head;
        ListNode result = new ListNode(0);
        
        while(curr != null){
            ListNode nextNode = curr.next;
            ListNode findOrder = result;
            while(findOrder.next != null && findOrder.next.val < curr.val){
                findOrder = findOrder.next;
            }
            
            curr.next = findOrder.next;
            findOrder.next = curr;
            curr = nextNode;
        }

        return result.next;
    }
}