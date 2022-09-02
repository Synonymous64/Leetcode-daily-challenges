function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}

var averageOfLevels = function(root) {
    let res = new Array();
    let q = [root];
    while(q.length){
        let size = q.length;
        let sum = 0;
        let count = size;
        while(count--){
            let curr = q.shift()
            if(curr.left) q.push(curr.left);
            if(curr.right) q.push(curr.right);
            sum += curr.val;
        }
        res.push(sum/size);
    }
    return res;
};
let p1 = new TreeNode(3);
let p2 = new TreeNode(9);
let p3 = new TreeNode(20);
let p4 = new TreeNode(15);
let p5 = new TreeNode(7);
p1.left = p2;
p1.right = p3;
p3.left = p4;
p3.right = p5;

console.table(averageOfLevels(p1));