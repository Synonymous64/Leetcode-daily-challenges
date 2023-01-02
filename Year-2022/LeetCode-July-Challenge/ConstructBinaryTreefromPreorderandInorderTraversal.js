function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

var buildTree = function(preorder, inorder) {
    p = i = 0
    build = function(stop) {
        if (inorder[i] != stop) {
            var root = new TreeNode(preorder[p++])
            root.left = build(root.val)
            i++
            root.right = build(stop)
            return root
        }
        return null
    }
    return build()
};
const inorderTraversal = (root) =>{
    if(root != null){
        inorderTraversal(root.left);
        console.log(root.val);
        inorderTraversal(root.right);
    }
}

let preorder = [1,2], inorder = [2,1];
let root = buildTree(preorder, inorder);
inorderTraversal(root);
