function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
var countNodes = function(root) {
    const helper = (root, leftCount = 1, rightCount = 1) => {
        if(!root) return 0;
        let lefty = root, righty = root;
        while(lefty = lefty.left) leftCount++;
        while(righty = righty.right) rightCount++;
        if(leftCount === rightCount) return (1 << leftCount) - 1;
        return 1 + helper(root.left) + helper(root.right);
    }
    return helper(root);
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

console.log(countNodes(p1));