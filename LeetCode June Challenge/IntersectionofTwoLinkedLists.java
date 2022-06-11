class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}
public class IntersectionofTwoLinkedLists {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode p1 = headA, p2 = headB;
        while(p1 != p2){
            if(p1 != null) p1 = p1.next;
            else p1 = headA;
            if(p2 != null) p2 = p2.next;
            else p2 = headB;
        }
        return p1;
    }
    public static void main(String[] args) {
        
    }
}
