var largestAltitude = function(gain) {
    let res = 0, temp = 0;
    for(let x of gain){
        temp += x;
        res = Math.max(res, temp);
    }
    return res;
};

let gain = [-5,1,5,0,-7];
console.log(largestAltitude(gain));