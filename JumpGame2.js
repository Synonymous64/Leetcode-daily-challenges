var jump = function(nums) {
    let jumps = 0, farthest = 0, current = 0;
    for(let i = 0; i < nums.length - 1; ++i){
        farthest = Math.max(farthest, nums[i] + i);
        if(current === i){
            jumps++;
            current = farthest;
        }
    }
    return jumps;
};
let nums = [2,3,1,1,4];
console.log(jump(nums));