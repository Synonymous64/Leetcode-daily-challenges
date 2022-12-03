var frequencySort = function (s) {
    let freq = {};
    for (let ch of s)
        freq[ch] ? freq[ch]++ : freq[ch] = 1;
    let arr = [];
    for (let x in freq)
        arr.push([freq[x], x])
    arr.sort((a, b) => b[0] - a[0]);
    let res = "";
    for (let x of arr)
        for (let i = 0; i < x[0]; ++i)
            res += x[1];
    return res;
};
console.log(frequencySort("tree"));