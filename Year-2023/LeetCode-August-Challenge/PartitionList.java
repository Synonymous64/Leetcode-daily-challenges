class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode partition(ListNode head, int x) {
        if(head == null) return head;
        ListNode smallerEli = new ListNode(-1);
        ListNode greaterEli = new ListNode(-1);
        smallerEli.next = head;
        greaterEli.next = head;

        ListNode smallerHead = smallerEli;
        ListNode greaterHead = greaterEli;

        while(head != null){
            if(head.val < x){
                smallerEli.next = head;
                smallerEli = smallerEli.next;
            } else{
                greaterEli.next = head;
                greaterEli = greaterEli.next;
            }
            head = head.next;
        }

        greaterEli.next = null;
        smallerEli.next = greaterHead.next;
        return smallerHead.next;
    }
}
public class PartitionList {
    public static void main(String[] args) {
        
    }
}
