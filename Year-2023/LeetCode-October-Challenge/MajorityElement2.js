var majorityElement = function (nums) {
    let mp = {};
    let mySet = new Set();
    let res = [];

    for (let x of nums) {
        mp[x] ? mp[x]++ : mp[x] = 1;
        if (mp[x] > nums.length / 3) {
            mySet.add(x);
        }
    }

    for (let x of mySet) res.push(x);
    return res;
};

let nums = [3,2,3];
console.log(majorityElement(nums));