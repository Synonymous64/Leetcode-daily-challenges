var orderlyQueue = function (s, k) {
    if (k === 1) {
        let res = s;
        let n = s.length;
        let doubleString = s + s;
        for (let i = 1; i < n; ++i) {
            let str = doubleString.substr(i, n);
            if (str < res) {
                res = str;
            }
        }
        return res;
    }
    [...s].sort().join('');
    return s;
};
let s = "baaca", k = 3;
console.log(orderlyQueue(s, k));