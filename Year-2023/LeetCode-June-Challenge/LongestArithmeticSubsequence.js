var longestArithSeqLength = function(nums) {
    let dp = new Array(nums.length);
    for(let i = 0; i < nums.length; ++i)
        dp[i] = new Array(1011).fill(1);
    let res = 1;

    for(let i = 1; i < nums.length; ++i){
        for(let j = i - 1; j >= 0; --j){
            let d = nums[i] - nums[j] + 500;
            dp[i][d] = Math.max(dp[i][d], dp[j][d] + 1);
            res = Math.max(res, dp[i][d]);
        }
    }
    return res;
};

let nums = [3,6,9,12];
console.log(longestArithSeqLength(nums));