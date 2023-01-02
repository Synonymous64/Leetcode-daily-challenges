function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
let isBST = function(root, minimum = null, maximum = null){
    if(!root) return true;
    if(minimum && root.val <= minimum.val) return false;
    if(maximum && root.val >= maximum.val) return false;
    let leftValid = isBST(root.left, minimum, root);
    let rightValid = isBST(root.right, root, maximum);
    return leftValid & rightValid;
}
var isValidBST = function(root) {
    return isBST(root);
};
let p1 = new TreeNode(2);
let p2 = new TreeNode(1);
let p3 = new TreeNode(3);

p1.left = p2;
p1.right = p3;

console.log(isValidBST(p1));