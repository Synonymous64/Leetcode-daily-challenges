var isAnagram = function(s, t) {
    if(s.length !== t.length) return false;
    const count = {};
    const n = s.length;
    for(let i = 0; i < n; ++i){
        if(!count[t[i]]) count[t[i]] = 0;
        if(!count[s[i]]) count[s[i]] = 0;
        count[t[i]]++;
        count[s[i]]--;
    }
    for(let ch in count){
        if(count[ch] !== 0) return false;
    }
    return true;
};
let s = "rat", t = "car";
let s1 = "anagram", t1 = "nagaram"
console.log(isAnagram(s, t));
console.log(isAnagram(s1, t1));