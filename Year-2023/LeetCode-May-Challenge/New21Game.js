var new21Game = function (n, k, maxPts) {
    if (k === 0 || n >= k + maxPts) return 1.0;
    let dp = [n + 1];
    dp[0] = 1.0;

    let sum = 1.0, res = 0.0;
    for (let i = 1; i <= n; ++i) {
        dp[i] = sum / maxPts;
        if (i < k) sum += dp[i];
        else res += dp[i];
        if (i >= maxPts) sum -= dp[i - maxPts];
    }
    return res;
};

let n = 10, k = 1, maxPts = 10;
console.log(new21Game(n, k, maxPts));