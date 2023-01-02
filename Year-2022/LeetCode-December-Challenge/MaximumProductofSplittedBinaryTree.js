function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

var maxProduct = function(root) {
    let totalSum = 0, res = 0;
    let mod = 1e9+7;
    const helper = (root) => {
        if(!root) return 0;
        let sum = 0;
        sum += helper(root.left) + helper(root.right) + root.val;
        res = Math.max(res, (totalSum - sum) * sum);
        return sum;
    }
    totalSum = helper(root);
    helper(root);
    return res % mod;
};