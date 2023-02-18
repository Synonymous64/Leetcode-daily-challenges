function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

var invertTree = function(root) {
    if(!root) return null;
    invertTree(root.left);
    invertTree(root.right);
    let temp = root.left;
    root.left = root.right;
    root.right = temp;
    return root;
};