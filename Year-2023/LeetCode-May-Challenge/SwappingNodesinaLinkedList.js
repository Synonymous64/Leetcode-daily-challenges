function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

var swapNodes = function (head, k) {
    let first = head;
    while (--k) first = first.next;
    let temp = first;
    let second = head;
    while (temp.next) {
        temp = temp.next;
        second = second.next;
    }
    let swap = first.val;
    first.val = second.val;
    second.val = swap;
    return head;
};