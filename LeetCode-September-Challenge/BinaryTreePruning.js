function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

var pruneTree = function (root) {
  if (root) {
    root.left = pruneTree(root.left);
    root.right = pruneTree(root.right);
    if (root.val === 0 && root.left === null && root.right === null)
      return null;
  }
  return root;
};
const inorderTraversal = (root) => {
  if (root) {
    inorderTraversal(root.left);
    console.log(root.val);
    inorderTraversal(root.right);
  }
};
let p1 = new TreeNode(1);
let p2 = new TreeNode(0);
let p3 = new TreeNode(0);
let p4 = new TreeNode(1);
let p6 = pruneTree(p1);
inorderTraversal(p6);
