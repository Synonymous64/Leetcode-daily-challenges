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
    private int count = 0;
    private void DFS(TreeNode root, int[] Freq){
        if(root == null) return;
        Freq[root.val]++;
        if(root.left == null && root.right == null){
            int getCount = 0;
            for(int i : Freq)
            if(i % 2 == 1) getCount++;
            if(getCount <= 1) count++;
        }
        DFS(root.left, Freq);
        DFS(root.right, Freq);
        Freq[root.val]--;
    }
    public int pseudoPalindromicPaths (TreeNode root) {
        int[] Freq = new int[10];
        Arrays.fill(Freq, 0);
        DFS(root, Freq);
        return count;
    }
}
public class PseudoPalindromicPathsinaBinaryTree {
    public static void main(String[] args) {
            TreeNode p1 = new TreeNode(2);
            TreeNode p2 = new TreeNode(3);
            TreeNode p3 = new TreeNode(1);
            TreeNode p4 = new TreeNode(3);
            TreeNode p5 = new TreeNode(1);
            TreeNode p6 = new TreeNode(1);
        
            p1.left = p2;
            p1.right = p3;
            p2.left = p4;
            p2.right = p5;
            p3.right = p6;
        
            Solution s = new Solution();
            System.out.println(s.pseudoPalindromicPaths(p1));
    }
}
