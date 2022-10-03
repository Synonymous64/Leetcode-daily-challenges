var minCost = function(colors, neededTime) {
    let i = 0, j = 0, n = neededTime.length, totalTime = 0;
    while(i < n && j < n){
        let currTime = 0, maxTime = 0;
        while(j < n && colors[i] === colors[j]){
            maxTime = Math.max(maxTime, neededTime[j]);
            currTime += neededTime[j];
            ++j;
        }
        i = j;
        totalTime += (currTime - maxTime);
    }
    return totalTime;
};
let colors = "aaabbbabbbb";
let neededTime = [3,5,10,7,5,3,5,5,4,8,1];
console.log(minCost(colors, neededTime));