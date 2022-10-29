var earliestFullBloom = function(plantTime, growTime) {
    let n = plantTime.length, days = [];
    for(let i = 0; i < n; ++i){
        days.push([plantTime[i], growTime[i]]);
    }
    days.sort((a, b) => b[1] - a[1]);
    let start = 0, res = 0;
    for(let x of days){
        start += x[0];
        res = Math.max(res, start + x[1]);
    }
    return res;
};
let plantTime = [1,4,3], growTime = [2,3,1];
console.log(earliestFullBloom(plantTime, growTime));