var mergeAlternately = function (word1, word2) {
    let word1Len = word1.length, word2Len = word2.length;
    let i = 0, j = 0;
    let res = "";
    while (i < word1Len && j < word2Len) {
        res += word1[i++];
        res += word2[j++];
    }
    while (i < word1Len) res += word1[i++];
    while (j < word2Len) res += word2[j++];
    return res;
};

let word1 = "ab", word2 = "pqrs";
console.log(mergeAlternately(word1, word2));