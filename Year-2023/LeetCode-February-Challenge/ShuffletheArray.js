var shuffle = function(nums, n) {
    let res = [];
    for(let i = 0; i < n; ++i){
        res.push(nums[i]);
        if(i + n < nums.length){
            res.push(nums[i + n]);
        }
    }
    return res;
};
let nums = [2,5,1,3,4,7], n = 3;
console.log(shuffle(nums, n));