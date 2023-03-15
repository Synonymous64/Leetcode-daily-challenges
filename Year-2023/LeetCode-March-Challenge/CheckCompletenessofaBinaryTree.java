import java.util.*;

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
    public boolean isCompleteTree(TreeNode root) {
        if (root == null)
            return true;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        boolean check = false;
        while (!q.isEmpty()) {
            TreeNode curr = q.poll();
            if (curr.left != null) {
                if (check)
                    return false;
                q.add(curr.left);
            } else
                check = true;
            if (curr.right != null) {
                if (check)
                    return false;
                q.add(curr.right);
            } else
                check = true;
        }
        return true;
    }
}

public class CheckCompletenessofaBinaryTree {
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
        System.out.println(s.isCompleteTree(p1));
    }
}