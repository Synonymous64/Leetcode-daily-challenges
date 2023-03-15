function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

var isCompleteTree = function (root) {
    if (!root) return true;
    let q = [root];
    let check = false;

    while (q.length) {
        let curr = q.shift();
        if (curr.left) {
            if (check) return false;
            q.push(curr.left);
        } else check = true;

        if (curr.right) {
            if (check) return false;
            q.push(curr.right);
        } else check = true;
    }
    return true;
};

let p1 = new TreeNode(1);
let p2 = new TreeNode(2);
let p3 = new TreeNode(3);
let p4 = new TreeNode(4);
let p5 = new TreeNode(5);
let p6 = new TreeNode(6);

p1.left = p2;
p1.right = p3;
p2.left = p4;
p2.right = p5;
p3.left = p6;

console.log(isCompleteTree(p1));