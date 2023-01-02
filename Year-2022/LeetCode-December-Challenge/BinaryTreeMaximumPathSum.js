function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
var maxPathSum = function(root) {
    let maxSum = -Infinity;
    const helper = (root) =>{
        if(!root) return 0;
        let left = Math.max(0, helper(root.left));
        let right = Math.max(0, helper(root.right));
        maxSum = Math.max(maxSum, left + right + root.val);
        return Math.max(left, right) + root.val;
    }
    helper(root);
    return maxSum;
};