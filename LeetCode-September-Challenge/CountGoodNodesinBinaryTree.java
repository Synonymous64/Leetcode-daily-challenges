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
    private int count = 0;
    private void countGoodNodes(TreeNode root, int randMax){
        if(root == null) return;
        if(root.val >= randMax) {
            count++;
            randMax = root.val;
        }
        countGoodNodes(root.left, randMax);
        countGoodNodes(root.right, randMax);
    }
    public int goodNodes(TreeNode root) {
        if(root == null) return count;
        countGoodNodes(root, root.val);
        return count;
    }
}
public class CountGoodNodesinBinaryTree {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(3);
        TreeNode p2 = new TreeNode(1);
        TreeNode p3 = new TreeNode(4);
        TreeNode p4 = new TreeNode(3);
        TreeNode p5 = new TreeNode(1);
        TreeNode p6 = new TreeNode(5);
        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
        p3.left = p5;
        p3.right = p6;
    
        Solution s = new Solution();
        System.out.println(s.goodNodes(p1));
    }
}
