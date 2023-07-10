function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}
var minDepth = function (root) {
    if (!root) return 0;
    let left = minDepth(root.left), right = minDepth(root.right);
    return 1 + (Math.min(left, right) ? Math.min(left, right) : Math.max(left, right));
};

let p1 = new TreeNode(3);
let p2 = new TreeNode(9);
let p3 = new TreeNode(20);
let p4 = new TreeNode(15);
let p5 = new TreeNode(7);

p1.left = p2;
p1.right = p3;
p3.left = p4;
p4.right = p5;

console.log(minDepth(p1));