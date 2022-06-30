class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode (int value){
        val = value;
        left = null;
        right = null;
    }
}
class Solution {
    private int MONITERED = -1, HAS_CAMERA = 0, NEED_CAMERA = 1, count = 0;
    private int minCameraInfo(TreeNode root){
        if(root == null) return MONITERED;
        int left = minCameraInfo(root.left);
        int right = minCameraInfo(root.right);
        if(left == NEED_CAMERA || right == NEED_CAMERA){
            count++;
            return HAS_CAMERA;
        }
        else if(left == HAS_CAMERA || right == HAS_CAMERA) return MONITERED;
        return NEED_CAMERA;
    }
    public int minCameraCover(TreeNode root) {
        int rootminCameraInfo = minCameraInfo(root);
        if(rootminCameraInfo == NEED_CAMERA) return count + 1;
        return count;
    }
}
public class BinaryTreeCameras{
    public static void main(String[] args) {
        TreeNode p1 = new TreeNode(0);
        TreeNode p2 = new TreeNode(0);
        TreeNode p3 = new TreeNode(0);
        TreeNode p4 = new TreeNode(0);
        p1.left = p2;
        p2.left = p3;
        p2.right = p4;
        Solution s = new Solution();
        System.out.println(s.minCameraCover(p1));
    }
}