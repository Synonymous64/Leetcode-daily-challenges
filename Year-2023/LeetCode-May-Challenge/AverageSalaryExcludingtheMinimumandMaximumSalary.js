var average = function (salary) {
    let sum = 0, minVal = Number.MAX_VALUE, maxVal = Number.MIN_VALUE;
    for (let x of salary) {
        sum += x;
        minVal = Math.min(minVal, x);
        maxVal = Math.max(maxVal, x);
    }
    sum -= (minVal + maxVal);
    return sum / (salary.length - 2);
};

let salary = [4000, 3000, 1000, 2000];
console.log(average(salary));