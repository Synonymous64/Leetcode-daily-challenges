var uniquePaths = function (m, n) {
    let dp = new Array(m);
    for (let i = 0; i < dp.length; ++i)
        dp[i] = new Array(n).fill(1);

    for (let i = 1; i < m; ++i)
        for (let j = 1; j < n; ++j)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    return dp[m - 1][n - 1];
};

let m = 3, n = 7;
console.log(uniquePaths(m, n));