var bagOfTokensScore = function (tokens, power) {
    tokens.sort((a, b) => a - b); let  i = 0, j = tokens.length - 1, score = 0, res = 0;
    while(i <= j){
        if(tokens[i] <= power){
            score++;
            power -= tokens[i++];
            if(res < score) res = score;
        } else if(score > 0){
            score--;
            power += tokens[j--];
        } else break
    }
    return res;
};
let tokens = [81, 45, 8], power = 32;
console.log(bagOfTokensScore(tokens, power));
