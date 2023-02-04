var checkInclusion = function(s1, s2) {
    let s1Size = s1.length;
    let S2Size = s2.length;
    if(s1Size > S2Size) return false;
    let window = new Array(26).fill(0);

    for(let i = 0; i < s1Size; ++i){
        window[s1.charCodeAt(i) - 97]++;
        window[s2.charCodeAt(i) - 97]--;
    }
    if(!window.some(e => e !== 0)) return true;

    for(let i = s1Size; i < S2Size; ++i){
        window[s2.charCodeAt(i) - 97]--;
        window[s2.charCodeAt(i - s1Size) - 97]++;
        if(!window.some(e => e !== 0)) return true;
    }
    return false;
};

let s1 = "ab", s2 = "eidbaooo";
console.log(checkInclusion(s1, s2));