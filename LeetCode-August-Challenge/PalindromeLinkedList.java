class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
class Solution {
    private ListNode reverseList(ListNode head){
        ListNode prev = null, curr = head, newNode = null;
        while(curr != null){
            newNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = newNode;
        }
        head = prev;
        return prev;
    }
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        if(fast != null) slow = slow.next;
        ListNode reverseNode = reverseList(slow);
        while(reverseNode != null){
            if(reverseNode.val == head.val){
                reverseNode = reverseNode.next;
                head = head.next;
            } else return false;
        }
        return true;
    }
}
public class PalindromeLinkedList {
    public static void main(String[] args) {
        
    }
}
