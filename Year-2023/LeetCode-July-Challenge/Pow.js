var myPow = function (x, n) {
    let res = 1;
    if (n === 0 || x === 1) return 1;
    else if (n < 0) {
        x = 1 / x;
        n = -n;
    }

    res *= x;
    n--;
    let t = 0;

    while (n) {
        t++;
        if (t < n) {
            res *= res;
            n -= t;
            t += t;
        } if (n > 0) {
            res *= x;
            n--;
        }
    }
    return res;
};

let x = 2.00000, n = 10;
console.log(myPow(x, n));