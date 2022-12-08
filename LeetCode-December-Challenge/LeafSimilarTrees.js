function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}
var leafSimilar = function (root1, root2) {
    let root1Val = new Array(), root2Val = new Array();
    const helper = (root, sum) => {
        if (root) return;
        if (!root.left && !root.right) sum.push(root.val);
        helper(root.left, sum);
        helper(root.right, sum);
    }g
    helper(root1, root1Val);
    helper(root2, root2Val);
    if (root1Val.length !== root2Val.length) return false;
    for (let i = 0; i < root1Val.length; ++i)
        if (root1Val[i] !== root2Val[i]) return false;
    return true;
};