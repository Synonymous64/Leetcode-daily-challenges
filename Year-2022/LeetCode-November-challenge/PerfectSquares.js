var numSquares = function (n) {
    if(Math.ceil(Math.sqrt(n)) === Math.floor(Math.sqrt(n))) return 1;
    while(n % 4 == 0) n /= 4;
    if(n % 8 == 7) return 4;
    for(let i = 0; i * i <= n; ++i){
        let base = Number.parseInt(Math.sqrt(n - i * i));
        if(base * base === (n - i * i)) return 2;
    }
    return 3;
};
console.log(numSquares(11));