var findErrorNums = function(nums) {
    nums.sort((a, b)=> a - b);
    let n = nums.length, res = new Array(2);
    for(let i = 0; i < n - 1; ++i)
        if(nums[i] === nums[i + 1]) res[0] = nums[i], nums[i] = 0;
    let sum = n;
    for(let i = 0; i < n; ++i) sum ^= i ^ nums[i];
    res[1] = sum;
    return res;
};
let nums = [1,2,2,4];
console.log(findErrorNums(nums));