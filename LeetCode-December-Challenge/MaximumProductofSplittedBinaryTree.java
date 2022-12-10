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
    private long totalSum = 0;
    private long res = 0;
    private int helper(TreeNode root){
        if(root == null) return 0;
        long sum = 0;
        sum += helper(root.left) + helper(root.right) + root.val;
        res = Math.max(res, (totalSum - sum) * sum);
        return ((int)sum) ;
    }
    public int maxProduct(TreeNode root) {
        totalSum = helper(root);
        helper(root);
        return (int)(res % (int)(1e9 + 7));
    }
}
public class MaximumProductofSplittedBinaryTree {
    public static void main(String[] args) {
        
    }
}
