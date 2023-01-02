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
    public List<Integer> inorderTraversal(TreeNode root) {
        if(root != null){
            res = inorderTraversal(root.left);
            res.add(root.val);
            res = inorderTraversal(root.right);
        }
        return res;
    }
}
public class BinaryTreeInorderTraversal{
    public static void main(String[] args) {
        
    }
}