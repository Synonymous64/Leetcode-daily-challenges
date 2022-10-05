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
    private void helper(TreeNode root, int val, int depth, int currDepth){
        if(root == null) return;
        if(currDepth == depth - 1){
            TreeNode temp = root.left;
            root.left = new TreeNode(val);
            root.left.left = temp;
            temp = root.right;
            root.right = new TreeNode(val);
            root.right.right = temp;
        }
        helper(root.left, val, depth, currDepth + 1);
        helper(root.right, val, depth, currDepth + 1);

    }
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth == 1){
            TreeNode node = new TreeNode(val);
            node.left = root;
            return node;
        }
        helper(root, val, depth, 1);
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
public class AddOneRowtoTree{
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(4);
        TreeNode p2 = new TreeNode(2);
        TreeNode p3 = new TreeNode(6);
        TreeNode p4 = new TreeNode(3);
        TreeNode p5 = new TreeNode(1);
        TreeNode p6 = new TreeNode(5);
    
        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
        p2.right = p5;
        p3.left = p6;
        int val = 1, depth = 2;
        Solution s = new Solution();
        TreeNode root = s.addOneRow(p1, val, depth);
        s.inorderTraversal(root);
    }
}