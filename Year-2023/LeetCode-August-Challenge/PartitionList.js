var partition = function(head, x) {
    if(head === null) return null;
    let smallerEli = new ListNode(-1);
    let greaterEli = new ListNode(-1);
    smallerEli.next = head;
    greaterEli.next = head;
    let smallerHeadEli = smallerEli;
    let greaterHeadEli = greaterEli;
    while(head){
        if(head.val < x){
            smallerEli.next = head;
            smallerEli = smallerEli.next;
        } else{
            greaterEli.next = head;
            greaterEli = greaterEli.next;
        }
        head = head.next;
    }
    greaterEli.next = null;
    smallerEli.next = greaterHeadEli.next;
    return smallerHeadEli.next;
};