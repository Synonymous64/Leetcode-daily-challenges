var canPlaceFlowers = function(flowerbed, n) {
    for(let i = 0; i < flowerbed.length; ++i){
        if((flowerbed[i] === 0) && (i === 0 || flowerbed[i - 1] === 0) && (i === flowerbed.length - 1 || flowerbed[i + 1] === 0)){
            flowerbed[i] = 1;
            n--;
        }
    }
    return n <= 0;
};

let flowerbed = [1,0,0,0,0,1], n = 2;
console.log(canPlaceFlowers(flowerbed, n));