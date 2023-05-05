var maxVowels = function (s, k) {
    let countVowels = 0, tempCount = 0;
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === 'a' || s[i] === 'e' || s[i] === 'i' || s[i] === 'o' || s[i] === 'u') tempCount++;
        if (i - k >= 0)
            if (s[i - k] === 'a' || s[i - k] === 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u') tempCount--;
        if (tempCount > countVowels) countVowels = tempCount;
    }
    return countVowels;
};

let s = "abciiidef", k = 3;
console.log(maxVowels(s, k));