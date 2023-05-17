function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

var pairSum = function (head) {
    let list = new Array();
    let temp = head;
    while (temp) {
        list.push(temp.val);
        temp = temp.next;
    }
    let res = 0, n = list.length;
    for (let i = 0; i < n / 2; ++i) res = Math.max(res, list[i] + list[n - i - 1]);
    return res;
};