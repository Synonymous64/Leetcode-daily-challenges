function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

var longestZigZag = function (root) {
    let res = 0;
    const helper = (root, check, checkSteps) => {
        if (!root) return;
        res = Math.max(res, checkSteps);
        if (check) {
            helper(root.left, false, checkSteps + 1);
            helper(root.right, true, 1);
        } else {
            helper(root.right, true, checkSteps + 1);
            helper(root.left, false, 1);
        }
        return;
    }
    helper(root, true, 0);
    helper(root, false, 0);
    return res;
};

let p1 = new TreeNode(1);
let p2 = new TreeNode(1);
let p3 = new TreeNode(1);
let p4 = new TreeNode(1);
let p5 = new TreeNode(1);
let p6 = new TreeNode(1);
let p7 = new TreeNode(1);

p1.left = p2;
p1.right = p3;
p2.right = p4;
p4.left = p5;
p4.right = p6;
p5.right = p7;

console.log(longestZigZag(p1));