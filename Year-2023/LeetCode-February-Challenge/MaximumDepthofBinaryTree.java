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
    public int maxDepth(TreeNode root) {
        return root == null ? 0: 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}
public class MaximumDepthofBinaryTree{
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(3);
        TreeNode p2 = new TreeNode(9);
        TreeNode p3 = new TreeNode(20);
        TreeNode p4 = new TreeNode(15);
        TreeNode p5 = new TreeNode(7);

        p1.left = p2;
        p1.right = p3;
        p3.left = p4;
        p3.right = p5;
        
        Solution s = new Solution();
        System.out.println(s.maxDepth(p1));
    }
}