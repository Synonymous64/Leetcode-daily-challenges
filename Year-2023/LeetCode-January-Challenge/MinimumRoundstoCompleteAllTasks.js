var minimumRounds = function(tasks) {
    let res = 0, mp = {};
    for(let x of tasks) mp[x] ? mp[x]++ : mp[x] = 1;
    for(let x of Object.values(mp)){
        if(x <= 1) return -1;
        else if(x === 2) res++;
        else res += Math.ceil((x)/3.0);
    }
    return res;
};
let tasks = [2,2,3,3,2,4,4,4,4,4];
console.log(minimumRounds(tasks));