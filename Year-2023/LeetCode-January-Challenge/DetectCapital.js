var detectCapitalUse = function(word) {
    return word === word.toUpperCase() || word === word[0] + word.substr(1).toLowerCase();
};
let word = "ua";
console.log(detectCapitalUse(word));