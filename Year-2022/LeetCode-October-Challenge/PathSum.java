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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;
        if(root.left == null && root.right == null && targetSum - root.val == 0) return true;
        return hasPathSum(root.left, targetSum - root.val) || hasPathSum(root.right, targetSum - root.val);
    }
}
public class PathSum{
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(5);
        TreeNode p2 = new TreeNode(4);
        TreeNode p3 = new TreeNode(8);
        TreeNode p4 = new TreeNode(11);
        TreeNode p5 = new TreeNode(13);
        TreeNode p6 = new TreeNode(4);
        TreeNode p7 = new TreeNode(7);
        TreeNode p8 = new TreeNode(2);
        TreeNode p9 = new TreeNode(1);
        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
        p3.left = p5;
        p3.right = p6;
        p4.left = p7;
        p4.right = p8;
        p6.left = p9;
        int targetSum = 22;
        Solution s = new Solution();
        System.out.println(s.hasPathSum(p1, targetSum));
    }
}