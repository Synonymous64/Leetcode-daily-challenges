import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}
class Solution {
    private ArrayList<Integer> res = new ArrayList<>();
    private void toArray(ListNode head){
        ListNode temp = head;
        while(temp != null){
            res.add(temp.val);
            temp = temp.next;
        }
        return;
    }
    private TreeNode arrBST(ArrayList<Integer> res, int low, int high){
        if(low >= high) return null;
        int mid = low + (high - low)/2;
        TreeNode newTree = new TreeNode(res.get(mid));
        newTree.left = arrBST(res, low, mid);
        newTree.right = arrBST(res, mid + 1, high);
        return newTree;
    }
    public TreeNode sortedListToBST(ListNode head) {
        toArray(head);
        return arrBST(res, 0, res.size());
    }
}

public class ConvertSortedListtoBinarySearchTree {
    public static void main(String[] args) {

    }
}
