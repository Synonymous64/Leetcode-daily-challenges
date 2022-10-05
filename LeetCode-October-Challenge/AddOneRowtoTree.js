function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
var addOneRow = function(root, val, depth) {
    if(depth === 1){
        let node = new TreeNode(val);
        node.left = root;
        return node;
    }
    const helper = (root, val, depth, currDepth)=>{
        if(!root) return;
        if(currDepth === depth - 1){
            let temp = root.left;
            root.left = new TreeNode(val);
            root.left.left = temp;
            temp = root.right;
            root.right = new TreeNode(val);
            root.right.right = temp;
        }
        helper(root.left, val, depth, currDepth + 1);
        helper(root.right, val, depth, currDepth + 1);
    }
    helper(root, val, depth, 1);
    return root;
};