function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

var isSymmetric = function (root) {
    if (!root) return true;

    const helper = (left, right) => {
        if(!left && !right) return true;
        if((!left && right) || (!right && left) || (left.val !== right.val)) return false;
        return helper(left.right, right.left) && helper(left.left, right.right);
    }

    return helper(root.left, root.right);
};
let p1 = new TreeNode(1);
let p2 = new TreeNode(2);
let p3 = new TreeNode(2);
let p4 = new TreeNode(3);
let p5 = new TreeNode(4);
let p6 = new TreeNode(4);
let p7 = new TreeNode(3);

p1.left = p2;
p1.right = p3;
p2.left = p4;
p2.right = p5;
p3.left = p6;
p3.right = p7;

console.log(isSymmetric(p1));