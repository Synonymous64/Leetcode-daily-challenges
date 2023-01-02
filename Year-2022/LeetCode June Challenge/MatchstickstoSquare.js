var helper = (matchsticks, target, sides, index) => {
    if(index == matchsticks.length){
        if(sides[0] === sides[1] && sides[1] === sides[2] && sides[2] === sides[3]) return true;
        return false;
    }
    for(let i = 0; i < 4; ++i){
        if(sides[i] + matchsticks[index] > target) continue;
        let j = i - 1;
        while(j >= 0){
            if(sides[j] === sides[i]) break;
            j--;
        }
        if(j != -1) continue;
        sides[i] += matchsticks[index];
        if(helper(matchsticks, target, sides, index + 1)) return true;
        sides[i] -= matchsticks[index];
    }
    return false;
}
var makesquare = function(matchsticks) {
    if(matchsticks.length === 0) return false;
    let sides = new Array(4);
    sides.fill(0);
    let sum = 0;
    for(let i = 0; i < matchsticks.length; ++i){
        sum += matchsticks[i];
    }
    let target = sum/4;
    matchsticks.sort((a, b) => b - a);
    if(matchsticks[0] > target) return false;
    return helper(matchsticks, target, sides, 0);
};
let matchsticks = [1,1,2,2,2];
console.log(makesquare(matchsticks));