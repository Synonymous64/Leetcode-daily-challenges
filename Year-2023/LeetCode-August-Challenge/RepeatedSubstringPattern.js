var repeatedSubstringPattern = function(s) {
    let str = s + s;
    return str.substring(1, str.length - 1).includes(s);
};

let s = "abab";
console.log(repeatedSubstringPattern(s));