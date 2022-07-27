function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

var flatten = function(root) {
    let curr = root;
    while(curr){
        if(curr.left){
            let pred = curr.left;
            while(pred.right) pred = pred.right;
            pred.right = curr.right;
            curr.right = curr.left;
            curr.left = null;
        }
        curr = curr.right;
    }
};