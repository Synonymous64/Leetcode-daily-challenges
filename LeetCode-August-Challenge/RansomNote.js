var canConstruct = function(ransomNote, magazine) {
    let res = {};
    for(let ch of magazine) res[ch] ? res[ch]++ : res[ch] = 1;
    for(let ch of ransomNote){
        if(!res[ch]) return false;
        res[ch]--;
    }
    return true;
};
let ransomNote = "aa", magazine = "aab";
console.log(canConstruct(ransomNote, magazine));