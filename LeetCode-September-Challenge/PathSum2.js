function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}
var pathSum = function (root, targetSum) {
  const helper = (root, targetSum, temp, res) => {
    if (!root) return;
    temp.push(root.val);
    if (!root.left && !root.right && root.val === targetSum) res.push(temp);
    helper(root.left, targetSum - root.val, Array.from(temp), res);
    helper(root.right, targetSum - root.val, Array.from(temp), res);
  };
  let res = [];
  let temp = new Array();
  helper(root, targetSum, temp, res);
  return res;
};
let p1 = new TreeNode(5);
let p2 = new TreeNode(4);
let p3 = new TreeNode(8);
let p4 = new TreeNode(11);
let p5 = new TreeNode(13);
let p6 = new TreeNode(4);
let p7 = new TreeNode(7);
let p8 = new TreeNode(2);
let p9 = new TreeNode(5);
let p10 = new TreeNode(1);

p1.left = p2;
p1.right = p3;
p2.left = p4;
p3.left = p5;
p3.right = p6;
p4.left = p7;
p4.right = p8;
p6.left = p9;
p6.right = p10;

let res = pathSum(p1, 22);
console.table(res);
