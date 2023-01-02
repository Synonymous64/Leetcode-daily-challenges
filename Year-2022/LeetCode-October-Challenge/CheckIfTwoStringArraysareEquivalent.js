var arrayStringsAreEqual = function(word1, word2) {
    let wordIdx1 = 0, wordIdx2 = 0;
    let idx1 = 0, idx2 = 0;
    while(wordIdx1 < word1.length && wordIdx2 < word2.length){
        if(word1[wordIdx1][idx1] !== word2[wordIdx2][idx2]) return false;
        idx1++, idx2++;
        if(idx1 == word1[wordIdx1].length){
            idx1 = 0;
            wordIdx1++;
        }
        if(idx2 == word2[wordIdx2].length){
            idx2 = 0;
            wordIdx2++;
        }
    }
    return wordIdx1 === word1.length && wordIdx2 === word2.length;
};
let word1 = ["ab", "c"], word2 = ["a", "bc"];
console.log(arrayStringsAreEqual(word1, word2));