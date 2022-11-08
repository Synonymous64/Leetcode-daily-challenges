var makeGood = function(s) {
    for(let i = 0; i < s.length - 1; ++i){
        if(Math.abs(s.charCodeAt(i) - s.charCodeAt(i + 1)) === 32){
            return makeGood(s.substr(0, i) + s.substr(i + 2));
        }
    }
    return s;
};
let s = "leEeetcode";
console.log(makeGood(s));