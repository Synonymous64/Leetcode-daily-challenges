var findJudge = function(n, trust) {
    let trusted = new Array(n + 1).fill(0);
    for(let [x, y] of trust){
        trusted[x]--;
        trusted[y]++;
    }
    let res = -1;
    for(let i = 1; i <= n; ++i)
        if(trusted[i] === n - 1) return res = i;
    return res;
};
let n = 2, trust = [[1,2]];
console.log(findJudge(n, trust));