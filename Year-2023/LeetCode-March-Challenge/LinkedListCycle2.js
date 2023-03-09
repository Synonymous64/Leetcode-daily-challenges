function ListNode(val) {
    this.val = val;
    this.next = null;
}

var detectCycle = function (head) {
    let slow = head, fast = head;

    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
        if (slow === fast) break;
    }

    if (!fast || !fast.next) return null;
    fast = head;

    while (fast != slow) {
        slow = slow.next;
        fast = fast.next;
    }
    return slow;
};