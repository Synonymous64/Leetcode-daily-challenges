class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode p = head;
        for(int i = 1; i <= n; ++i) p = p.next;
        ListNode q = head;
        if(p != null){
            while(p.next != null){
                p = p.next;
                q = q.next;
            }
            ListNode temp = q.next;
            q.next = temp.next;
        } else {
            head = head.next;
        }
        return head;
    }
}
public class RemoveNthNodeFromEndofList {
    public static void main(String[] args) {
        
    }
}
