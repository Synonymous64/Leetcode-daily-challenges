function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
let MONITERED = -1, HAS_CAMERA = 0, NEED_CAMERA = 1, count = 0;
var minCameraInfo = function(root) {
    if(root === null) return MONITERED;
    let left1 = minCameraInfo(root.left);
    let right1 = minCameraInfo(root.right);

    if(left1 === NEED_CAMERA || right1 === NEED_CAMERA){
        count++;
        return HAS_CAMERA;
    }
    else if(left1 === HAS_CAMERA || right1 === HAS_CAMERA) return MONITERED;
    return NEED_CAMERA;
}
var minCameraCover = function(root) {
    let rootMincameraInfo = minCameraInfo(root);
    if(rootMincameraInfo === NEED_CAMERA) return count + 1;
    return count; 
};
let p1 = new TreeNode(0); 
let p2 = new TreeNode(0); 
let p3 = new TreeNode(0); 
let p4 = new TreeNode(0); 
p1.left = p2;
p2.left = p3;
p2.right = p4;
console.log('====================================');
console.log(minCameraCover(p1));
console.log('====================================');