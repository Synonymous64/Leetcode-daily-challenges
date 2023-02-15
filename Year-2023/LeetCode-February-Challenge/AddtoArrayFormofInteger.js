var addToArrayForm = function(num, k) {
    let res = [];
    for(let i = num.length - 1; i >= 0; --i){
        num[i] += k;
        k = Math.trunc(num[i] / 10);
        res.unshift(Math.trunc(num[i] % 10));
    }
    while(k > 0){
        res.unshift(Math.trunc(k % 10));
        k = Math.trunc(k / 10);
    }
    return res;
};
let num = [1,2,0,0], k = 34;
console.log(addToArrayForm(num, k));