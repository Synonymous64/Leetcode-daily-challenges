var isPowerOfThree = function(n) {
    // while(n >= 3){
    //     if(n % 3 != 0) return false;
    //     n = n / 3;
    // }
    // return n == 1;
    if(n < 1) return false;
    if(n == 1) return true;
    if(n % 3 != 0) return false;
    return isPowerOfThree(n / 3);
};
console.log(isPowerOfThree(27));