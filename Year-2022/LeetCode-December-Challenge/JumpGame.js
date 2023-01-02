var canJump = function(nums) {
    let n = nums.length - 1;
    let lastPos = n;
    for(let i = n; i >= 0; --i)
        if(nums[i] + i >= lastPos) lastPos = i;
    return lastPos === 0;
};
let nums = [2,3,1,1,4];
console.log(canJump(nums));