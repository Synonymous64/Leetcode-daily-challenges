var minFlipsMonoIncr = function(s) {
    let minFlips = 0, counter = 0;
    for(let ch of s){
        if(ch === '1') counter++;
        else minFlips++;
        minFlips = Math.min(minFlips, counter);
    }
    return minFlips;
};
let s = "00110";
console.log(minFlipsMonoIncr(s));