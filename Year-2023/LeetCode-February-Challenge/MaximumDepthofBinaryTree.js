function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

var maxDepth = function(root) {
    return root === null ? 0: 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
};

let p1 = new TreeNode(3);
let p2 = new TreeNode(9);
let p3 = new TreeNode(20);
let p4 = new TreeNode(15);
let p5 = new TreeNode(7);

p1.left = p2;
p1.right = p3;
p3.left = p4;
p3.right = p5;

console.log(maxDepth(p1));