function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

var mergeKLists = function (lists) {
    if (!lists.length) return null;

    const mergekthLists = (l1, l2) => {
        if (!l1) return l2;
        if (!l2) return l1;

        let head = new ListNode();
        if (l1.val <= l2.val) head = l1;
        else head = l2;

        if (l1.val <= l2.val) head.next = mergekthLists(l1.next, l2);
        else head.next = mergekthLists(l1, l2.next);
        return head;
    }

    let head = lists[0];

    for (let i = 1; i < lists.length; ++i)
        head = mergekthLists(head, lists[i]);

    return head;
};