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
    private boolean isBST(TreeNode root, TreeNode minimum, TreeNode maximum){
        if(root == null) return true;
        if(minimum != null && root.val <= minimum.val) return false;
        if(maximum != null && root.val >= maximum.val) return false;
        boolean leftValid = isBST(root.left, minimum, root);
        boolean rightValid = isBST(root.right, root, maximum);
        return leftValid & rightValid;
    }
    public boolean isValidBST(TreeNode root) {
        TreeNode minimum = null, maximum = null;
        return isBST(root, minimum, maximum);
    }
}
public class ValidateBinarySearchTree {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode (2);
        TreeNode p2 = new TreeNode(1);
        TreeNode p3 = new TreeNode(3);

        p1.left = p2;
        p1.right = p3;

        Solution s = new Solution();
        System.out.println(s.isValidBST(p1));
    }
}
