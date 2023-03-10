function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
}

var Solution = function (head) {
    this.count = 0;
    this.headNode = null;
    headNode = head;
    let temp = headNode;
    while (temp) {
        count++;
        temp = temp.next;
    }
};

Solution.prototype.getRandom = function () {
    let randomIndex = Math.floor(Math.random() * this.count);
    let temp = this.headNode;
    for (let i = 0; i < randomIndex; ++i) {
        temp = temp.next;
    }
    return temp.val;
};

