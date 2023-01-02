var minimumTotal = function(triangle) {
    let n = triangle.length;
    let dp = new Array(n);
    dp.fill(0);
    for(let i = 0; i < n; ++i){
        dp[i] = triangle[n - 1][i];
    }
    for(let i = n - 2; i >= 0; --i){
        for(let j = 0; j < triangle[i].length; ++j){
            dp[j] = Math.min(dp[j], dp[j + 1]) + triangle[i][j];
        }
    }
    return dp[0];
};
