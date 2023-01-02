var isPossible = function(target) {
    let sum = 0, max =0;
    for(let i = 0; i < target.length; ++i){
        sum += target[i];
        if(target[max] < target[i]){
            max = i;
        }
    }
    let diff = sum - target[max];
    if(diff == 1 || target[max] == 1) return true;
    if(diff > target[max] || diff == 0 || target[max] % diff == 0) return false;
    target[max] %= diff;
    return isPossible(target);
};
let target = [9,3,5];
console.log(isPossible(target));