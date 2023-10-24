var backspaceCompare = function (s, t) {
    let sLen = s.length - 1;
    let tLen = t.length - 1;
    let sCount = 0, tCount = 0;

    while (sLen >= 0 && tLen >= 0) {
        if (s[sLen] === '#') {
            sCount++;
            sLen--;
        } else if (t[tLen] === '#') {
            tCount++;
            tLen--;
        } else if (s[sLen] !== '#' && sCount > 0) {
            sCount--;
            sLen--;
        } else if (t[tLen] !== '#' && tCount > 0) {
            tCount--;
            tLen--;
        } else if (s[sLen] !== t[tLen]) return false;
        else {
            sCount = 0;
            tCount = 0;
            sLen--;
            tLen--;
        }
    }

    while (sLen >= 0) {
        if (s[sLen] === '#') {
            sCount++;
            sLen--;
        } else if (s[sLen] !== '#' && sCount > 0) {
            sCount--;
            sLen--;
        } else return false;
    }

    while (tLen >= 0) {
        if (t[tLen] === '#') {
            tCount++;
            tLen--;
        } else if (t[tLen] !== '#' && tCount > 0) {
            tCount--;
            tLen--;
        } else return false;
    }

    return true;
};

let s = "ab#c", t = "ad#c";
console.log(backspaceCompare(s, t));