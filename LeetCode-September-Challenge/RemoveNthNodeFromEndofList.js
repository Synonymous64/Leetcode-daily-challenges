function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}
var removeNthFromEnd = function(head, n) {
    let p = head;
    for(let i = 1; i <= n; ++i) p = p.next;
    let q = head;
    if(p){
        while(p.next){
            p = p.next;
            q = q.next;
        }
        let temp = q.next;
        q.next = temp.next;
        
    } else{
        head = head.next;
    }
    return head;
};