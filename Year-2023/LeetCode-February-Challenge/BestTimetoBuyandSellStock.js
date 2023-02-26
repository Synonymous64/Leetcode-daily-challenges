var maxProfit = function(prices) {
    let minPrices = Infinity, maxProfit = -1;
    for(let x of prices){
        minPrices = Math.min(minPrices, x);
        maxProfit = Math.max(maxProfit, x - minPrices);
    }
    return maxProfit;
};

let prices = [7,1,5,3,6,4];
console.log(maxProfit(prices));