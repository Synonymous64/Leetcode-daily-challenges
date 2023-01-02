function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
var goodNodes = function(root) {
    let count = 0;
    const countGoodNodes = (root, randMax) => {
        if(!root) return count;
        if(root.val >= randMax) count++, randMax = root.val;
        countGoodNodes(root.left, randMax);
        countGoodNodes(root.right, randMax);
    }
    if(!root) return count;
    countGoodNodes(root, root.val);
    return count;
};
