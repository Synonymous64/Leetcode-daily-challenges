var isValid = function (s) {
    const isValidParenthesis = (a, b) => {
        if (a === '(' && b === ')') return true;
        if (a === '{' && b === '}') return true;
        if (a === '[' && b === ']') return true;
        return false;
    }
    let stack = new Array(), checker = '';
    for (let ch of s) {
        if (ch === '(' || ch == '{' || ch == '[') stack.push(ch);
        else if (ch === ')' || ch === '}' || ch == ']') {
            if (stack.length === 0) return false;
            checker = stack.at(stack.length - 1);
            if (!isValidParenthesis(checker, ch)) return false;
            stack.pop();
        }
    }
    return stack.length === 0 ? true : false;
};
let s = "()[]{}";
console.log(isValid(s));