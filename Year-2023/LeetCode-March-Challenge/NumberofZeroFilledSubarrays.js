var zeroFilledSubarray = function (nums) {
    let count = 0, res = 0;
    for (let x of nums) {
        if (x) count = 0;
        else count++;
        res += count;
    }
    return res;
};
let nums = [1,3,0,0,2,0,0,4];
console.log(zeroFilledSubarray(nums));