class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || root == p || root == q) return root;
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if(left == null) return right;
        if(right == null) return left;
        return root;
    }
    void inorderTraversal(TreeNode root){
        if(root != null){
            inorderTraversal(root.left);
            System.out.print(root.val + " ");
            inorderTraversal(root.right);
        }
    }
}
public class LowestCommonAncestorofaBinarySearchTree {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(6);
        TreeNode p2 = new TreeNode(2);
        TreeNode p3 = new TreeNode(8);
        TreeNode p4 = new TreeNode(0);
        TreeNode p5 = new TreeNode(4);
        TreeNode p6 = new TreeNode(7);
        TreeNode p7 = new TreeNode(9);
        TreeNode p8 = new TreeNode(3);
        TreeNode p9 = new TreeNode(5);

        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
        p2.right = p5;
        p3.left = p6;
        p3.right = p7;
        p5.left = p8;
        p5.right = p9;

        Solution s = new Solution();
        // s.inorderTraversal(p1);
        TreeNode res = s.lowestCommonAncestor(p1, p2, p3);
        System.out.println(res.val);
    }
}
