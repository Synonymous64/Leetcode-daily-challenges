var rob = function(nums) {
    let dp = new Array(101);
    dp.fill(-1);
    const helper = (idx, nums) => {
        if(idx >= nums.length) return 0;
        if(dp[idx] != -1) return dp[idx];
        let take = helper(idx + 2, nums) + nums[idx];
        let noTake = helper(idx + 1, nums);
        return dp[idx] = Math.max(take, noTake);
    }
    return helper(0, nums);
};
let nums = [2,1,1,2];
console.log(rob(nums));