var maxIceCream = function(costs, coins) {
    costs.sort((a , b) => a - b);
    if(costs[0] > coins) return 0;
    let count = 0;
    for(let i = 0; i < costs.length; ++i){
        if(costs[i] <= coins){
            count++;
            coins -= costs[i];
        } else return count;
    }
    return count;
};
let costs = [10,2,10,10,10,10,8,2,7,8], coins = 25;
console.log(maxIceCream(costs, coins));