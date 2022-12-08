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
    private void helper(TreeNode root, ArrayList<Integer> res){
        if(root == null) return;
        if(root.left == null && root.right == null) res.add(root.val);
        helper(root.left, res);
        helper(root.right, res);
    }
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        ArrayList<Integer> res1 = new ArrayList<>();
        ArrayList<Integer> res2 = new ArrayList<>();
        helper(root1, res1);
        helper(root2, res2);
        if(res1.size() != res2.size()) return false;
        for(int i = 0; i < res1.size(); ++i)
            if(res1.get(i) != res2.get(i)) return false; 
        return true;
    }
}
public class LeafSimilarTrees{
    public static void main(String[] args) {
        
    }
}