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
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        int left = minDepth(root.left), right = minDepth(root.right);
        return 1 + (Math.min(left, right) != 0? Math.min(left, right) : Math.max(left, right));
    }
}

public class MinimumDepthofBinaryTree{
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(3);
        TreeNode p2 = new TreeNode(9);
        TreeNode p3 = new TreeNode(20);
        TreeNode p4 = new TreeNode(15);
        TreeNode p5 = new TreeNode(7);

        p1.left = p2;
        p1.right = p3;
        p3.left = p4;
        p4.right = p5;

        Solution s = new Solution();
        System.out.println(s.minDepth(p1));
    }
}