function Node(val, children) {
  this.val = val;
  this.children = children;
}

var levelOrder = function (root) {
    if(!root) return []; let q = [];
    q.push(root); let res = [];
    while(q.length > 0){
        let size = q.length;
        let temp = new Array();
        while(size--){
            let curr = q.shift();
            for(let i = 0; i < curr.children.length; ++i) q.push(curr.children[i]);
            temp.push(curr.val);
        }
        res.push(temp);
    }
    return res;
};
var levelOrder = function (root) {
    if(!root) return []; let q = [root]; let res = [];
    while(q.length > 0){
        let size = q.length;
        let temp = new Array();
        while(size--){
            let curr = q.shift();
            q.push(...curr.children);
            temp.push(curr.val);
        }
        res.push(temp);
    }
    return res;
};

