var minInsertions = function (s) {
    let n = s.length;
    let rev = s.split("").reverse().join("");
    let dp = new Array(n + 1);
    for (let i = 0; i < dp.length; ++i) {
        dp[i] = new Array(n + 1);
    }
    for (let i = 0; i < n + 1; ++i) {
        for (let j = 0; j < n + 1; ++j) {
            if (i === 0 || j === 0) dp[i][j] = 0;
        }
    }
    for (let i = 1; i < n + 1; ++i) {
        for (let j = 1; j < n + 1; ++j) {
            if (s[i - 1] === rev[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return n - dp[n][n];
};
let s = "mbadm";
console.log(minInsertions(s));