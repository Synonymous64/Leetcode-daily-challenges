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
    private int res = 0;
    private void helper(TreeNode root, boolean check, int checkSteps){
        if(root == null) return;
        res = Math.max(res, checkSteps);
        if(check){
            helper(root.left, false, checkSteps + 1);
            helper(root.right, true, 1);
        }else{
            helper(root.right, true, checkSteps + 1);
            helper(root.left, false, 1);
        }
        return;
    }
    public int longestZigZag(TreeNode root) {
        helper(root, true, 0);
        helper(root, false, 0);
        return res;
    }
}
public class LongestZigZagPathinaBinaryTree {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(1);
        TreeNode p2 = new TreeNode(1);
        TreeNode p3 = new TreeNode(1);
        TreeNode p4 = new TreeNode(1);
        TreeNode p5 = new TreeNode(1);
        TreeNode p6 = new TreeNode(1);
        TreeNode p7 = new TreeNode(1);

        p1.left = p2;
        p1.right = p3;
        p2.right = p4;
        p4.left = p5;
        p4.right = p6;
        p5.right = p7;

        System.out.println(new Solution().longestZigZag(p1));
    }
}
