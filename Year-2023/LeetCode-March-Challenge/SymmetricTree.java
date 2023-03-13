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
    private boolean helper(TreeNode left, TreeNode right){
        if(left == null && right == null) return true;
        if((left == null && right != null) || (right == null && left != null) || (left.val != right.val)) return false;
        return helper(left.right, right.left) && helper(left.left, right.right);
    }
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        return helper(root.left, root.right);
    }
}
public class SymmetricTree {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(1);
        TreeNode p2 = new TreeNode(2);
        TreeNode p3 = new TreeNode(2);
        TreeNode p4 = new TreeNode(3);
        TreeNode p5 = new TreeNode(4);
        TreeNode p6 = new TreeNode(4);
        TreeNode p7 = new TreeNode(3);

        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
        p2.right = p5;
        p3.left = p6;
        p3.right = p7;

        Solution s = new Solution();

        System.out.println(s.isSymmetric(p1));
    }
}
