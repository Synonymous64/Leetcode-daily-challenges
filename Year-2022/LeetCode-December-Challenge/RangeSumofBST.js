function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

var rangeSumBST = function(root, low, high) {
    let res = 0;
    const inorderTraversal = (root, low, high) => {
        if(root){
            inorderTraversal(root.left, low, high);
            if(root.val >= low && root.val <= high) res += root.val;
            inorderTraversal(root.right, low, high);
        }
    }
    inorderTraversal(root, low, high);
    return res;
};
