var validateStackSequences = function (pushed, popped) {
    let top = 0, stack = [];
    for (let x of pushed) {
        stack.push(x);
        while (stack.length && stack[stack.length - 1] === popped[top]) {
            stack.pop();
            top++;
        }
    }
    return !stack.length;
};
let pushed = [1, 2, 3, 4, 5], popped = [4, 5, 3, 2, 1];
console.log(validateStackSequences(pushed, popped));