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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> res = new ArrayList<>();
        Queue<TreeNode > q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size = q.size();
            double sum = 0;
            int count = size;
            while(count-- > 0){
                TreeNode curr = q.poll();
                sum += curr.val;
                if(curr.left != null) q.add(curr.left);
                if(curr.right != null) q.add(curr.right);
            }
            res.add(sum / size);
        }
        return res;
    }
}
public class AverageofLevelsinBinaryTree {
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(3);
        TreeNode p2 = new TreeNode(9);
        TreeNode p3 = new TreeNode(20);
        TreeNode p4 = new TreeNode(15);
        TreeNode p5 = new TreeNode(7);

        p1.left = p2;
        p1.right = p3;
        p3.left = p4;
        p3.right = p5;
        List<Double> res = new ArrayList<>();
        Solution s = new Solution();
        res = s.averageOfLevels(p1);
        for(int i = 0; i < res.size(); ++i){
            System.out.print(res.get(i) + " ");
        }
    }
}
