class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    private int count = 0;
    private ListNode headNode = null;

    public Solution(ListNode head) {
        headNode = head;
        ListNode temp = headNode;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
    }

    public int getRandom() {
        double randomIndex = Math.random() % count;
        ListNode temp = headNode;
        for (int i = 0; i < (int) randomIndex; ++i) {
            temp = temp.next;
        }
        return temp.val;
    }
}