var StockSpanner = function () {
    this.stack = [];
};

StockSpanner.prototype.next = function (price) {
    let res = 1;
    const { stack } = this;
    while (stack.length && price >= stack[stack.length - 1][0]) {
        res += stack[stack.length - 1][1];
        stack.pop();
    }
    stack.push([price, res]);
    return res;
};
let re = new StockSpanner();
console.log(re.next(100));
console.log(re.next(80));
console.log(re.next(60));
console.log(re.next(70));
console.log(re.next(60));
console.log(re.next(75));
console.log(re.next(85));