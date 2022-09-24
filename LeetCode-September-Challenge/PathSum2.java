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
    private void helper(TreeNode root, int targetSum, List<Integer>temp, List<List<Integer>> res){
        if(root == null) return;
        temp.add(root.val);
        if(root.left == null && root.right == null && root.val == targetSum) res.add(temp);
        helper(root.left, targetSum - root.val, new ArrayList<>(temp), res);
        helper(root.right, targetSum - root.val, new ArrayList<>(temp), res);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> res = new ArrayList<>();
        helper(root, targetSum, new ArrayList<>(), res);
        return res;
    }
    public void printCode(List<Integer> res){
        for(int i : res) System.out.print(i + " ");
    }
}
public class PathSum2 {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(5);
        TreeNode p2 = new TreeNode(4);
        TreeNode p3 = new TreeNode(8);
        TreeNode p4 = new TreeNode(11);
        TreeNode p5 = new TreeNode(13);
        TreeNode p6 = new TreeNode(4);
        TreeNode p7 = new TreeNode(7);
        TreeNode p8 = new TreeNode(2);
        TreeNode p9 = new TreeNode(5);
        TreeNode p10 = new TreeNode(1);
    
        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
        p3.left = p5;
        p3.right = p6;
        p4.left = p7;
        p4.right = p8;
        p6.left = p9;
        p6.right = p10;
    
        Solution s = new Solution();
        List<List<Integer>> res = s.pathSum(p1, 22);
        for(int i = 0; i < res.size(); ++i){
            s.printCode(res.get(i));
        }
    }
}
