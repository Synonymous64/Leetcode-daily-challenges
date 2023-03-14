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
    private int helper(TreeNode root, int sum){
        if(root == null) return 0;
        sum = sum * 10 + root.val;
        if(root.left == null && root.right == null) return sum;
        return helper(root.left, sum) + helper(root.right, sum);
    }
    public int sumNumbers(TreeNode root) {
        int sum = 0;
        return helper(root, sum);
    }
}
public class SumRoottoLeafNumbers {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(1);
        TreeNode p2 = new TreeNode(2);
        TreeNode p3 = new TreeNode(3);
        p1.left = p2;
        p1.right = p3;

        System.out.println(new Solution().sumNumbers(p1));
    }
}
