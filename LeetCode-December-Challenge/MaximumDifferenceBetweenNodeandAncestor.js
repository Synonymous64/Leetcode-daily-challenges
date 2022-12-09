function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

var maxAncestorDiff = function(root) {
    let minVal = 10000, maxVal = 0;
    const helper = (root, minVal, maxVal) => {
        if(!root) return maxVal - minVal;
        minVal = Math.min(minVal, root.val);
        maxVal = Math.max(maxVal, root.val);
        return Math.max(helper(root.left, minVal, maxVal), helper(root.right, minVal, maxVal));
    }
    return helper(root, minVal, maxVal);
};