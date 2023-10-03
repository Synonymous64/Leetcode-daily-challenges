var numIdenticalPairs = function(nums) {
    let res = 0;
    let mp = {};
    for(let i of nums) mp[i] ? mp[i]++ : mp[i] = 1;

    for(let x in mp){
        let n = mp[x];
        res += ((n) * (n - 1))/2;
    }
    return res;
};

let nums = [1,2,3,1,1,3];
console.log(numIdenticalPairs(nums));