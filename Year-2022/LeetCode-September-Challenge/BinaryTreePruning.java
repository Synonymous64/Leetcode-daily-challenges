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
    public TreeNode pruneTree(TreeNode root) {
        if(root != null){
            root.left = pruneTree(root.left);
            root.right = pruneTree(root.right);
            if(root.val == 0 && root.left == null && root.right == null) return null;
        }
        return root;
    }
    public void inorderTraversal(TreeNode root){
        if(root != null){
            inorderTraversal(root.left);
            System.out.print(root.val + " ");
            inorderTraversal(root.right);
        }
    }
}
public class BinaryTreePruning {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(1);
        TreeNode p2 = new TreeNode(0);
        TreeNode p3 = new TreeNode(0);
        TreeNode p4 = new TreeNode(1);
    
        p1.right = p2;
        p2.left = p3;
        p2.right = p4;
        Solution s = new Solution();
        p1 = s.pruneTree(p1);
        s.inorderTraversal(p1);
    }
}
