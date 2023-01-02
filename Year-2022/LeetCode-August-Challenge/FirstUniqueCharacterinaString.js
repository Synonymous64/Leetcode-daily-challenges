var firstUniqChar = function(s) {
    let counts = [];
    counts.fill(0);
    for(let ch of s) counts[ch] ? counts[ch]++ : counts[ch] = 1;
    for(let i = 0; i < s.length; ++i)   
        if(counts[s[i]] === 1) return i;
    return -1;
};
let s = "leetcode";
console.log(firstUniqChar(s));