function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

function TreeNode(val, left, right) {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

var sortedListToBST = function (head) {
    let res = [];

    const toArray = (head) => {
        let temp = head;
        while (temp) {
            res.push(temp.val);
            temp = temp.next;
        }
        return;
    }

    const arrBST = (res, low, high) => {
        if (low >= high) return null;
        let mid = low + Math.trunc((high - low) / 2);
        let newTree = new ListNode(res[mid]);
        newTree.left = arrBST(res, low, mid);
        newTree.right = arrBST(res, mid + 1, high);
        return newTree;
    }

    toArray(head);
    return arrBST(res, 0, res.length);
};