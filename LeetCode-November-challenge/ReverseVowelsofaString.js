var reverseVowels = function (s) {
    const isVowel = {
        a: 1,
        e: 1,
        i: 1,
        o: 1,
        u: 1,
        A: 1,
        E: 1,
        I: 1,
        O: 1,
        U: 1,
    }
    let low = 0, high = s.length - 1;
    let res = s.split('');
    while (low < high) {
        if (isVowel[res[low]] && isVowel[res[high]]) {
            //! Swapping 
            [res[low], res[high]] = [res[high], res[low]];
            low++, high--;
        } else if (!isVowel[s[low]]) low++;
        else high--;
    }
    return res.join('');
};
let s = "hello";
console.log(reverseVowels(s));
