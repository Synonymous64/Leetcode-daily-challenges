var maxConsecutiveAnswers = function (answerKey, k) {
    let T = 0, F = 0, curr = 0, res = 0;

    for (let i = 0; i < answerKey.length; ++i) {
        if (answerKey[i] === 'T') T++;
        else F++;
        if (Math.min(T, F) > k) {
            if (answerKey[curr] == 'T') T--;
            else F--;
            curr++;
        }
        res = Math.max(res, T + F);
    }
    return res;
};

let answerKey = "TTFF", k = 2;
console.log(maxConsecutiveAnswers(answerKey, k));