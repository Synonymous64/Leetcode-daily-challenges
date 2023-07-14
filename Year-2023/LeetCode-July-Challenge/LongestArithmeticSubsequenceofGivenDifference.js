var longestSubsequence = function (arr, difference) {
    let mp = {}, res = 1;

    for (let x of arr) {
        if (mp[x - difference])
            mp[x] = mp[x - difference] + 1;
        else mp[x] = 1;
        res = Math.max(res, mp[x]);
    }

    return res;
};

let arr = [1, 2, 3, 4], difference = 1;
console.log(longestSubsequence(arr, difference));