import java.util.*;
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
    private List<Integer> res = new ArrayList<>();
    private void preorder(TreeNode root){
        if(root != null){
            res.add(root.val);
            preorder(root.left);
            preorder(root.right);
        }
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        preorder(root);
        return res;
    }
}
public class BinaryTreePreorderTraversal {
    public static void main(String[] args) {
        
    }
}
