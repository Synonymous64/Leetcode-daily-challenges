var findNumberOfLIS = function (nums) {
    let n = nums.length;
    let dp = new Array(n).fill(1), count = new Array(n).fill(1);
    let res = 0, maxi = 1;

    for (let i = 0; i < n; ++i) {
        for (let prev = 0; prev < i; ++prev) {
            if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            } else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i]) count[i] += count[prev];
        }
        maxi = Math.max(maxi, dp[i]);
    }

    for (let i = 0; i < n; ++i) {
        if (maxi == dp[i])
            res += count[i];
    }

    return res;
};

let nums = [1, 3, 5, 4, 7];
console.log(findNumberOfLIS(nums));