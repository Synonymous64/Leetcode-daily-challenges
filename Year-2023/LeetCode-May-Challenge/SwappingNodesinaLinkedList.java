class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        ListNode first = head;
        while(--k != 0) first = first.next;
        ListNode temp = first;
        ListNode second = head;
        while(temp.next != null){
            temp = temp.next;
            second = second.next;
        }
        int swap = first.val;
        first.val = second.val;
        second.val = swap;
        return head;
    }
}
public class SwappingNodesinaLinkedList{
    public static void main(String[] args) {
        
    }
}