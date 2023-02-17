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
    private ArrayList<Integer> res = new ArrayList<>();
    private void inorderTraversal(TreeNode root){
        if(root != null){
            inorderTraversal(root.left);
            res.add(root.val);
            inorderTraversal(root.right);
        }
    }
    public int minDiffInBST(TreeNode root) {
        int minVal = Integer.MAX_VALUE;
        inorderTraversal(root);
        for(int i = 0; i < res.size() - 1; ++i)
            minVal = Math.min(minVal, res.get(i + 1) - res.get(i));
        return minVal;
    }
}

public class MinimumDistanceBetweenBSTNodes {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(4);
        TreeNode p2 = new TreeNode(2);
        TreeNode p3 = new TreeNode(6);
        TreeNode p4 = new TreeNode(1);
        TreeNode p5 = new TreeNode(3);

        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
        p2.right = p5;

        Solution s = new Solution();
        System.out.println(s.minDiffInBST(p1));
    }
}
