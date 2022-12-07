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
    private int res;
    private void inorderTraversal(TreeNode root, int low, int high){
        if(root != null){
            inorderTraversal(root.left, low, high);
            if(root.val >= low && root.val <= high) res += root.val;
            inorderTraversal(root.right, low, high);
        }
    }
    public int rangeSumBST(TreeNode root, int low, int high) {
        if(root == null) return 0;
        inorderTraversal(root, low, high);
        return res;
    }
}
public class RangeSumofBST {
    public static void main(String[] args) {
        
    }
}
