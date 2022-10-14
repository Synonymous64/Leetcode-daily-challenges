function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}
var deleteMiddle = function(head) {
    if(!head.next) return null;
    let fast = head.next.next;
    let slow = head;
    while(fast && fast.next){
        fast = fast.next.next;
        slow = slow.next;
    }
    slow.next = slow.next.next;
    return head;
};