function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}


var lowestCommonAncestor = function(root, p, q) {
    if(!root || root === p || root === q) return root;
    let left = lowestCommonAncestor(root.left, p, q);
    let right = lowestCommonAncestor(root.right, p, q);
    return !left ? right : !right ? left : root;
};
let inorderTraversal = function(root){
    if(root){
        inorderTraversal(root.left);
        console.log(root.val);
        inorderTraversal(root.right);
    }
}
let p1 = new TreeNode(6);
let p2 = new TreeNode(2);
let p3 = new TreeNode(8);
let p4 = new TreeNode(0);
let p5 = new TreeNode(4);
let p6 = new TreeNode(7);
let p7 = new TreeNode(9);
let p8 = new TreeNode(3);
let p9 = new TreeNode(5);

p1.left = p2;
p1.right = p3;
p2.left = p4;
p2.right = p5;
p3.left = p6;
p3.right = p7;
p5.left = p8;
p5.right = p9;

// inorderTraversal(p1);
let res = lowestCommonAncestor(p1, p2, p3);
console.log(res.val);