var maxSubarraySumCircular = function(nums) {
    const kedanes = (nums) => {
        let currSum = nums[0], maxSum = nums[0];
        for(let i = 1; i < nums.length; ++i){
            if(currSum < 0) currSum = 0;
            currSum += nums[i];
            maxSum = Math.max(currSum, maxSum);
        }
        return maxSum;
    }
    let x = kedanes(nums);
    let y = 0;
    for(let i = 0; i < nums.length; ++i){
        y += nums[i];
        nums[i] *= -1;
    }
    let z = kedanes(nums);
    if(y + z === 0) return x;
    return Math.max(x, y + z);
};
let nums = [1,-2,3,-2];
console.log(maxSubarraySumCircular(nums));