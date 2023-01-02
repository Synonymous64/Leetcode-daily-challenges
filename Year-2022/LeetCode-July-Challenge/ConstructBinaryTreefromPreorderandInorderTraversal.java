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
    private int preIdx = 0;
    private TreeNode build(int[] preorder, int[] inorder, int start, int end){
        if(start > end) return null;
        TreeNode root = new TreeNode(preorder[preIdx]);
        preIdx++; int inIdx = 0;
        for(int i = start; i <= end; ++i){
            if(root.val == inorder[i]){
                inIdx = i;
                break;
            }
        }
        root.left = build(preorder, inorder, start, inIdx - 1);
        root.right = build(preorder, inorder, inIdx + 1, end);
        return root;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return build(preorder, inorder, 0, inorder.length - 1);
    }
    public void inorder(TreeNode root){
        if(root != null){
            inorder(root.left);
            System.out.print(root.val + " ");
            inorder(root.right);
        }
    }
}
public class ConstructBinaryTreefromPreorderandInorderTraversal {
    public static void main(String[] args) {
        int[] preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
        Solution s = new Solution();
        TreeNode root = s.buildTree(preorder, inorder);
        s.inorder(root);
    }
}
