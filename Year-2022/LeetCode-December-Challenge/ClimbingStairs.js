var climbStairs = function (n) {
    let dp = new Array(46);
    dp.fill(-1);
    const helper = (n, dp) => {
        if(n <= 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
    return helper(n, dp);
};
console.log(climbStairs(45));