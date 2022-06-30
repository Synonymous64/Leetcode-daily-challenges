var minDeletions = function(s) {
    let freq = new Array(26).fill(0);
    let deletions = 0;
    for(let i = 0; i < s.length; ++i){
        const ele = s[i].charCodeAt(0) - 'a'.charCodeAt(0);
        freq[ele]++;
    }
    let mySet = new Set();
    for(let i = 0; i < 26; ++i){
        while(freq[i] > 0 && mySet.has(freq[i])){
            freq[i]--;
            deletions++;
        }
        mySet.add(freq[i]);
    }
    return deletions;
};
let s = "aaabbbcc";
console.log(minDeletions(s));