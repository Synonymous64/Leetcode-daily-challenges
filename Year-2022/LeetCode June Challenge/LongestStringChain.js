var longestStrChain = function(words) {
    words.sort((a, b) => a.length - b.length);
    let dp = {}; let ans = 0;
    for (let word of words){
        let len = 0;
        for(let i = 0; i < word.length; ++i){
            let predecessor = word.slice(0, i) + word.slice(i + 1);
            len = Math.max(len, (dp[predecessor] || 0) + 1);
        }
        dp[word] = Math.max(ans, len);
    }
    return Math.max(...Object.values(dp));
};
let words = ["a","b","ba","bca","bda","bdca"];
console.log(longestStrChain(words));