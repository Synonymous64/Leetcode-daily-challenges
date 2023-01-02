function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

var oddEvenList = function(head) {
    if(!head || !head.next || !head.next.next) return head;
    let odd = head, headOdd = odd, even = head.next, headEven = even;
    while(even && even.next){
        odd.next = even.next;
        even.next = even.next.next;
        odd = odd.next;
        even = even.next;
    }
    odd.next = headEven;
    return headOdd;
};