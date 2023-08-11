var change = function(amount, coins) {
    let dp = new Array(amount + 1).fill(0);
    dp[0] = 1;

    for(let x of coins){
        for(let i = 1; i <= amount; ++i){
            if(i - x >= 0){
                dp[i] += dp[i - x];
            }
        }
    }
    return dp[amount];
};

let amount = 5, coins = [1,2,5];
console.log(change(amount, coins));