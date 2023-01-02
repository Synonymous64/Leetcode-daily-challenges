var removeDuplicates = function (s) {
    let chars = s.split('');
    let res = [];
    for (let x of chars) {
        if (res.length && res[res.length - 1] == x) {
            res.pop();
        } else res.push(x);
    }
    return res.join('');
};
let s = "abbaca";
console.log(removeDuplicates(s));
