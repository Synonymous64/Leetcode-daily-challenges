let dp = new Array(1004);
var minCostClimbingStairsHelper = function(n, cost) {
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];
    if(dp[n] != -1) return dp[n];
    dp[n] = cost[n] +  Math.min(minCostClimbingStairsHelper(n - 1, cost), minCostClimbingStairsHelper(n - 2, cost))
    return dp[n];
};
var minCostClimbingStairs = function(cost) {
    let n = cost.length;
    dp.fill(-1);
    let ans = Math.min(minCostClimbingStairsHelper(n - 1, cost), minCostClimbingStairsHelper(n - 2, cost));
    return ans;
};

let cost = [1,100,1,1,1,100,1,1,100,1];
console.log(minCostClimbingStairs(cost));