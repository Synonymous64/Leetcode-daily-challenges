var findSpecialInteger = function (arr) {
    let mp = {};
    let n = arr.length;

    for (let x of arr) {
        mp[x] ? mp[x]++ : mp[x] = 1;
        if (mp[x] > n / 4) return x;
    }

    return -1;
};

let arr = [1,2,2,6,6,6,6,7,10];
console.log(findSpecialInteger(arr));