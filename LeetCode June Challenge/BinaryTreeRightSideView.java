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
    List<Integer> res = new ArrayList<>();
    private void helper(TreeNode root, int level){
        if(root == null) return;
        if(res.size() < level) res.add(root.val);
        helper(root.right, level + 1);
        helper(root.left, level + 1);
    }
    public List<Integer> rightSideView(TreeNode root) {
        helper(root, 1);
        return res;
    }
}

public class BinaryTreeRightSideView {
    public static void main(String[] args) {
        
    }
}
