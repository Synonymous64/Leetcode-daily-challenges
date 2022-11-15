class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private int helper(TreeNode root, int leftCount, int rightCount) {
        if (root == null)
            return 0;
        TreeNode lefty = root, righty = root;
        while (lefty.left != null) {
            lefty = lefty.left;
            leftCount++;
        }
        while (righty.right != null) {
            righty = righty.right;
            rightCount++;
        }
        if (leftCount == rightCount)
            return (1 << leftCount) - 1;
        return 1 + helper(root.left, leftCount, rightCount) + helper(root.right, leftCount, rightCount);
    }

    public int countNodes(TreeNode root) {
        int leftCount = 1, rightCount = 1;
        return helper(root, leftCount, rightCount);
    }
}

public class CountCompleteTreeNodes {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(1);
        TreeNode p2 = new TreeNode(2);
        TreeNode p3 = new TreeNode(3);
        TreeNode p4 = new TreeNode(4);
        TreeNode p5 = new TreeNode(5);
        TreeNode p6 = new TreeNode(6);
        
        p1.left = p2;
        p1.right = p3;
        p2.left = p4;
        p2.right = p5;
        p3.left = p6;
        
        Solution s = new Solution();
        System.out.println(s.countNodes(p1));
    }
}
