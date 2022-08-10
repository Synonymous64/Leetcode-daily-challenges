function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
let arrBST = function (nums, low, high){
    if(low >= high) return null;
    let mid = Math.floor((low+high)/2);
    let root = new TreeNode(nums[mid]);
    root.left = arrBST(nums, low, mid);
    root.right = arrBST(nums, mid + 1, high);
    return root;
}
var sortedArrayToBST = function (nums) {
    return arrBST(nums, 0, nums.length - 1);
};
