var maxProfit = function (prices, fee) {
    let profit = 0, effectiveBuyPrice = prices[0];

    for (let i = 0; i < prices.length; ++i) {
        profit = Math.max(profit, prices[i] - effectiveBuyPrice - fee);
        effectiveBuyPrice = Math.min(effectiveBuyPrice, prices[i] - profit);
    }
    return profit;
};

let prices = [1,3,2,8,4,9], fee = 2;
console.log(maxProfit(prices, fee));