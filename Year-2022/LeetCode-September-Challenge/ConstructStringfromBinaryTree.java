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
    public String tree2str(TreeNode root) {
        if(root == null) return "";
        String res = "";
        res += new String(root.val + "");
        if(root.left != null) res += "(" + tree2str(root.left) + ")";
        else if(root.right != null) res += "()";
        if(root.right != null) res += "(" + tree2str(root.right) + ")";
        return res;
    }
}
public class ConstructStringfromBinaryTree {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(1);
        TreeNode p2 = new TreeNode(2);
        TreeNode p3 = new TreeNode(3);
        TreeNode p4 = new TreeNode(4);
        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
    
        Solution s = new Solution();
        System.out.println(s.tree2str(p1));
    }
}
