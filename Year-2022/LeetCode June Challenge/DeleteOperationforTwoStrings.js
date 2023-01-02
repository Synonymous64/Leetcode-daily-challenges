var minDistance = function(word1, word2) {
    let word1Len = word1.length, word2Len = word2.length;
    let dp = new Array(word1Len + 1);
    for(let i = 0; i < word1Len + 1; ++i){
        dp[i] = new Array(word2Len + 1);
    }
    for(let i =  1; i < word1Len + 1; ++i){
        for(let j = 1; j < word2Len + 1; ++j){
            if(word1[i - 1] === word2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]); 
        }
    }
    let ans = (word1Len - dp[word1Len][word2Len]) + (word2Len - dp[word1Len][word2Len]);
    return ans;
};
let word1 = "sea", word2 = "eat"
console.log(minDistance(word1, word2));