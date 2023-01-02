var isPowerOfFour = function(n) {
    return n > 0 && Math.log2(n) % 2 === 0;
};
console.log(isPowerOfFour(16));