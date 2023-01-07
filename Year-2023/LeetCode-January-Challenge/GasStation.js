var canCompleteCircuit = function(gas, cost) {
    let res = 0, total = 0, index = 0;
    for(let i = 0; i < gas.length; ++i){
        let consume = gas[i] - cost[i];
        total += consume;
        if(total < 0){
            index = i + 1;
            total = 0;
        }
        res += consume;
    }
    return res < 0 ? -1: index;
};
let gas = [1,2,3,4,5], cost = [3,4,5,1,2];
console.log(canCompleteCircuit(gas, cost));