function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
var inorderTraversal = function (root) {
    let res = new Array();
    const inorder = (root) => {
        if(root){
            inorder(root.left);
            res.push(root.val);
            inorder(root.right);
        }
    }
    inorder(root);
    return res;
};
