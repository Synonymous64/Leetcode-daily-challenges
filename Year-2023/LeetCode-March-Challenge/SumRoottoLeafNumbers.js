function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}


var sumNumbers = function (root) {
    const helper = (root, sum = 0) => {
        if (!root) return 0;
        sum = sum * 10 + root.val;
        if (!root.left && !root.right) return sum;
        return helper(root.left, sum) + helper(root.right, sum);
    }
    return helper(root);
};

let p1 = new TreeNode(1);
let p2 = new TreeNode(2);
let p3 = new TreeNode(3);
p1.left = p2;
p1.right = p3;

console.log(sumNumbers(p1));