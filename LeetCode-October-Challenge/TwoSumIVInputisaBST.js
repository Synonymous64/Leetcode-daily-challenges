function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
var findTarget = function(root, k) {
    let res = new Array();
    const inorderTraversal = (root, res) => {
        if(root){
            inorderTraversal(root.left, res);
            res.push(root.val);
            inorderTraversal(root.right, res);
        }
    }
    inorderTraversal(root, res);
    let start = 0, end = res.length - 1;
    while(start < end){
        if(res[start] + res[end] === k) return true;
        else if(res[start] + res[end] < k) start++;
        else end--;
    }
    return false;
};