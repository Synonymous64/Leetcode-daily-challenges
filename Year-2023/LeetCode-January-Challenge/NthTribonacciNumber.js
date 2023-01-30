var tribonacci = function(n) {
    let dp = new Array(38).fill(-1);
    const helper = (n) => {
        if(n === 0) return 0;
        if(n === 1 || n === 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = helper(n - 1) + helper(n - 2) + helper(n - 3);
    }
    return helper(n);
};
let n = 25;
console.log(tribonacci(n));