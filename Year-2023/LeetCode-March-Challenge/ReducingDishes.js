var maxSatisfaction = function (satisfaction) {
    let n = satisfaction.length;
    const helper = (satisfaction, i, j, dp) => {
        if (i === satisfaction.length) return 0;
        if (dp[i][j] !== -1) return dp[i][j];
        let pick = j * satisfaction[i] + helper(satisfaction, i + 1, j + 1, dp);
        let notPick = helper(satisfaction, i + 1, j, dp);
        return dp[i][j] = Math.max(pick, notPick);
    }
    satisfaction.sort((a, b) => a - b);
    let dp = new Array(n + 1);
    for (let i = 0; i < n + 1; ++i) dp[i] = new Array(n + 1);
    for(let x of dp) x.fill(-1);
    return helper(satisfaction, 0, 1, dp);
};
let satisfaction = [-1, -8, 0, 5, -9];
console.log(maxSatisfaction(satisfaction));