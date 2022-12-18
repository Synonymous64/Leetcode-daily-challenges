var dailyTemperatures = function(temperatures) {
    let res = new Array(temperatures.length).fill(0);
    let stack = [];
    for(let i = 0; i < temperatures.length; ++i){
        while(stack.length && temperatures[stack[stack.length - 1]] < temperatures[i]){
            res[stack[stack.length - 1]] = i - stack[stack.length - 1];
            stack.pop();
        }
        stack.push(i);
    }
    return res;
};
let temperatures = [73,74,75,71,69,72,76,73];
console.log(dailyTemperatures(temperatures));