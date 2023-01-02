function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}


var levelOrder = function(root) {
    function traverse(node) {
        if (node) {
            if (level >= result.length) result[level] = []
            
            result[level].push(node.val)
            level++   
            traverse(node.left)
            traverse(node.right)
            level--
        }
    }
    let result = [], level = 0
    traverse(root)
    return result
}