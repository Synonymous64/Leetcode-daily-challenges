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
    private TreeNode arrBST(int[] nums, int low, int high){
        if(low >= high) return null;
        int mid = low + (high - low)/2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left = arrBST(nums, low, mid);
        root.right = arrBST(nums, mid + 1, high);
        return root;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return arrBST(nums, 0, nums.length);
    }
}
public class ConvertSortedArraytoBinarySearchTree {
    public static void main(String[] args) {
        
    }
}
