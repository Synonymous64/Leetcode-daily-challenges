var maxValueOfCoins = function (piles, k) {
    const helper = (i, piles, k, dp) => {
        if (i >= piles.length || k <= 0) return 0;
        if (dp[i][k] !== -1) return dp[i][k];
        let res = helper(i + 1, piles, k, dp);
        let curr = 0;
        for (let idx = 0; idx < piles[i].length && idx < k; ++idx) {
            curr += piles[i][idx];
            res = Math.max(res, curr + helper(i + 1, piles, k - idx - 1, dp));
        }
        return dp[i][k] = res;
    }
    let dp = new Array(piles.length);
    for (let i = 0; i < dp.length; ++i) dp[i] = new Array(k + 1).fill(-1);
    return helper(0, piles, k, dp);
};
let piles = [[1, 100, 3], [7, 8, 9]], k = 2;
console.log(maxValueOfCoins(piles, k));