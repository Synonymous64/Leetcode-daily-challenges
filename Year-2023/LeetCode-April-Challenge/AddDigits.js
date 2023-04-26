var addDigits = function (num) {
    while (num > 9) {
        let sum = 0;
        while (num) {
            sum += Math.trunc(num % 10);
            num = Math.trunc(num / 10);
        }
        num = sum;
    }
    return num;
};

let num = 38;
console.log(addDigits(num));