function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
var tree2str = function(root) {
    if(!root) return "";
    let res = "";
    res = new String(root.val);
    if(root.left) res += "(" + tree2str(root.left) + ")";
    else if(root.right) res += "()";
    if(root.right) res += "(" + tree2str(root.right) + ")";
    return res;
};
let p1 = new TreeNode(1);
let p2 = new TreeNode(2);
let p3 = new TreeNode(3);
let p4 = new TreeNode(4);
p1.left = p2;
p1.right = p3;
p2.left = p4;

console.log(tree2str(p1));