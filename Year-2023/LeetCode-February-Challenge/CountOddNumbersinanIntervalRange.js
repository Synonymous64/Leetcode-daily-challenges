var countOdds = function(low, high) {
    return Math.floor((high + 1)/2) - Math.floor(low / 2);
};
let low = 5, high = 7;
console.log(countOdds(low, high));