function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

var minDiffInBST = function (root) {
    let res = [];
    const inorderTraversal = (root) => {
        if(root){
            inorderTraversal(root.left);
            res.push(root.val);
            inorderTraversal(root.right);
        }
    }
    let minVal = Infinity;
    inorderTraversal(root);
    for(let i = 0; i < res.length - 1; ++i)
        minVal = Math.min(minVal, res[i + 1] - res[i]);
    return minVal;
};
let p1 = new TreeNode(4);
let p2 = new TreeNode(2);
let p3 = new TreeNode(6);
let p4 = new TreeNode(1);
let p5 = new TreeNode(3);

p1.left = p2;
p1.right = p3;
p2.left = p4;
p2.right = p5;

console.log(minDiffInBST(p1));