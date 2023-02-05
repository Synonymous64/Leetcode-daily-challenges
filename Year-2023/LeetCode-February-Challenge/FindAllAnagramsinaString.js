var findAnagrams = function(s, p) {
    let lenS = s.length;
    let lenP = p.length;
    if(lenP > lenS) return [];

    let count = new Array(26).fill(0);

    for(let i = 0; i < lenP; ++i){
        count[p.charCodeAt(i) - 97]++;
        count[s.charCodeAt(i) - 97]--;
    }
    let res = [];
    if(!count.some(e => e !== 0)) res.push(0);

    for(let i = lenP; i < lenS; ++i){
        count[s.charCodeAt(i - lenP) - 97]++;
        count[s.charCodeAt(i) - 97]--;
        if(!count.some(e => e !== 0)) res.push(i - lenP + 1);
    }
    return res;
};
let  s = "cbaebabacd", p = "abc";
console.log(findAnagrams(s, p))