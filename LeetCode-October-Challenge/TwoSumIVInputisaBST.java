import java.util.*;
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
    private void inorderTraversal(TreeNode root, ArrayList<Integer> res){
        if(root != null){
            inorderTraversal(root.left, res);
            res.add(root.val);
            inorderTraversal(root.right, res);
        }
    }
    public boolean findTarget(TreeNode root, int k) {
        ArrayList<Integer> res = new ArrayList<>();
        inorderTraversal(root, res);
        int start = 0, end = res.size() - 1;
        while(start < end){
            if(res.get(start) + res.get(end) == k) return true;
            else if(res.get(start) + res.get(end) < k) start++;
            else end--;
        }
        return false;
    }
}
public class TwoSumIVInputisaBST {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(5);
        TreeNode p2 = new TreeNode(3);
        TreeNode p3 = new TreeNode(6);
        TreeNode p4 = new TreeNode(2);
        TreeNode p5 = new TreeNode(4);
        TreeNode p6 = new TreeNode(7);

        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
        p2.right = p5;
        p3.left = p6;

        Solution s = new Solution();
        System.out.println(s.findTarget(p1, 9));
    }
}
