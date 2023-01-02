var evalRPN = function (tokens) {
    let stack = [];
    const obj = {
        '+': (a, b) => a + b,
        '-': (a, b) => a - b,
        '*': (a, b) => a * b,
        '/': (a, b) => a / b >= 0 ? Math.floor(a / b) : Math.ceil(a / b),
    };
    for (let x of tokens) {
        if (obj[x]) {
            let x2 = stack.pop();
            let x1 = stack.pop();
            stack.push(obj[x](x1, x2));
        } else stack.push(Number(x));
    }
    return stack.pop();
};
