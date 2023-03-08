var minEatingSpeed = function(piles, h) {
    let low = 1, high = piles[0];
    for(let x of piles) high = Math.max(high, x);

    while(low <= high){
        let mid = low + Math.trunc((high - low)/2);
        let count = 0;
        for(let i = 0; i < piles.length; ++i){
            if(piles[i] < mid) count++;
            else count += (Math.trunc(piles[i]/ mid) + (Math.trunc(piles[i] % mid) !== 0));
        }
        if(count > h) low = mid + 1;
        else high = mid - 1;
    }
    return low;
};

let piles = [3,6,7,11], h = 8;
console.log(minEatingSpeed(piles, h));