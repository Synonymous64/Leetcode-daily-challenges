var minDeletions = function (s) {
    let freq = new Array(26).fill(0), deletions = 0;
    for (let ch of s) {
        let ele = ch.charCodeAt(0) - 'a'.charCodeAt(0);
        freq[ele]++;
    }

    let mySet = new Set();

    for (let i = 0; i < 26; ++i) {
        while (freq[i] > 0 && mySet.has(freq[i])) {
            freq[i]--;
            deletions++;
        }
        mySet.add(freq[i]);g
    }
    return deletions;
};

let s = "ceabaacb";
console.log(minDeletions(s));