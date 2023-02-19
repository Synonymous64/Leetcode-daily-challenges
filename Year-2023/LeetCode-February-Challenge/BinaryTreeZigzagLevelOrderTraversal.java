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
    List<List<Integer>> res = new ArrayList<>();
    private void levelorder(TreeNode root){
        boolean flag = false;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            int size = q.size();
            LinkedList<Integer> temp = new LinkedList<>();
            flag = !flag;
            while(size-- != 0){
                TreeNode curr = q.poll();
                if(flag)
                    temp.add(curr.val);
                else temp.addFirst(curr.val);
                if(curr.left != null) q.add(curr.left);
                if(curr.right != null) q.add(curr.right);
            }
            res.add(temp);
        }
    }
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root == null) return new ArrayList<>();
        levelorder(root);
        return res;
    }
}
public class BinaryTreeZigzagLevelOrderTraversal{
    public static void main(String[] args) {
        
    }
}